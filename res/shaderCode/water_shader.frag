#version 420 core
out vec4 FragColor;

in vec2 texCoords;
in vec4 clipSpace;
in vec3 cameraVec;
in vec3 lightVec;



uniform sampler2D reflectionTexture;
uniform sampler2D refractionTexture;
//实现水面的波动效果
uniform sampler2D dudvMap;
uniform sampler2D normalMap;
uniform sampler2D depthTexture;
uniform sampler2D flowMap;
//设置时间以实现动态效果
uniform float time;
uniform vec2 tiling;
uniform vec3 lightColor;


const float waveStrength = 0.01;
const float shineDamper = 20.0;
const float reflectivity = 4.0;
void main() {

    //计算ndc坐标
    vec2 ndcCoords = (clipSpace.xy/clipSpace.w)/2.0 + 0.5;
    vec2 reflectTexCoords = vec2(ndcCoords.x, -ndcCoords.y);
    vec2 refractTexCoords = vec2(ndcCoords.x, ndcCoords.y);
    vec2 TexUV = vec2(texCoords.x * tiling.x, texCoords.y * tiling.y);

    //取出物体到摄像机的深度并转换为距离
    float near = 0.1f;
    float far = 1000.0f;
    float depth = texture(depthTexture, refractTexCoords).r;
    float floorDistance = 2.0 * near * far /(far + near -(2.0 * depth - 1.0) *(far - near));
    //取出水面到摄像机的深度并转换为距离
    depth = gl_FragCoord.z;
    float waterDistance = 2.0 * near * far /(far + near -(2.0 * depth - 1.0) *(far - near));
    //计算水面到水底物体的距离
    float waterDepth = floorDistance - waterDistance;
    waterDepth = clamp(sqrt(waterDepth/5), 0.0, 1.0);

    //提取dudvMap中的值，并乘上缩小系数
    //进行x和y方向的偏移
    vec2 flowSpeed = texture(dudvMap, texCoords*tiling*10).rg * 2.0 -1.0;
    vec2 distortedTexCoords = texture(dudvMap, vec2(TexUV.x + time, TexUV.y * tiling)).rg * 0.1;
    distortedTexCoords = TexUV + vec2(distortedTexCoords.x, distortedTexCoords.y + time);
    vec2 distortion = (texture(dudvMap, distortedTexCoords).rg * 2.0 - 1.0) * waveStrength;

    //        vec2 distortion = flowSpeed * time;


    //让反射和折射的纹理坐标加上偏移值,使其具有波动效果
    //使用clamp截断，防止在屏幕边缘出现渲染的黑缝
    reflectTexCoords += distortion;
    reflectTexCoords.x = clamp(reflectTexCoords.x, 0.001, 0.999);
    reflectTexCoords.y = clamp(reflectTexCoords.y, -0.999, -0.001);
    //todo 理解该方法
    refractTexCoords += distortion;

    refractTexCoords = clamp(refractTexCoords, 0.001, 0.999);

    //提取normalMap中的法向量,并使其集中向上
    vec4 normalMapColor = texture(normalMap, distortion);
    vec3 normal = vec3(normalMapColor.r * 2.0 - 1.0, normalMapColor.b * 10.0, normalMapColor.g * 2.0 - 1.0);
    normal = normalize(normal);

    //计算菲涅尔效应
    vec3 viewVec = normalize(cameraVec);
    float fresnelFactor = abs(dot(viewVec, normal));
    fresnelFactor = pow(fresnelFactor, 2);


    //高光效果
    vec3 reflectedLight = reflect(normalize(lightVec), normal);
    float specular = max(dot(reflectedLight, viewVec), 0.0);
    specular = pow(specular, shineDamper);
    vec3 specularLight = lightColor * specular * reflectivity * waterDepth;

    vec4 reflectColor = texture(reflectionTexture, reflectTexCoords);

    //计算折射
    vec3 refractDir = refract(cameraVec, vec3(0, 1, 0), 1.33);
    vec4 refractColor = texture(refractionTexture, refractTexCoords);


    FragColor = mix(reflectColor, refractColor, fresnelFactor);
    //FragColor.a = waterDepth;
    FragColor = mix(FragColor, + vec4(specularLight, 1.0), 0.2);


}