#version 330 core
out vec4 FragColor;
in vec3 Normal;
in vec3 lightPos;
in vec3 FragPos;
in vec3 viewPos;
uniform vec3 objectColor;
uniform vec3 lightColor;

void main() {
    //Ambient Color;
    float ambientStrength = 0.1;
    vec3 ambientColor = ambientStrength * lightColor;
    //Diffuse color;
    float diffusionColorStrength = 1.0;
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 normalizedNormal = normalize(Normal);
    vec3 diffusionColor = lightColor * max(dot(lightDir, normalizedNormal), 0.0) * diffusionColorStrength;
    //Speculate color;
    float specularStrength = .5;
    vec3 reflectedLight = reflect(-lightDir, normalizedNormal);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 speculateColor = pow(max(dot(viewDir, reflectedLight), 0.0), 128) * lightColor * specularStrength;
    vec3 result = (ambientColor + diffusionColor+ speculateColor) * objectColor;
    FragColor = vec4(result, 1.0);
}