#version 330
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
in vec3 ourColor;
  
uniform float ambientStrength;
uniform vec3 lightColor;

uniform vec3 lightPos; 

uniform vec3 viewPos; 
//uniform vec3 objectColor;

void main()
{
    //amb
    vec3 ambient = ambientStrength * vec3(1,0,0);
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(1,0,0);
    
    // specular
    float specularStrength = 1;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
   
    
    float spec = pow(max(dot(viewDir, reflectDir), 0), 40);
    //if(dot(norm, lightDir) < 0){
    //    spec = 0.0;
    //}
    vec3 specular = specularStrength * spec * vec3(1,1,1);  

    float distance = length(lightPos - FragPos);
    float attenuation = 1.0 / (1.0f + 0.09f * distance + 0.032f * (distance * distance));     
        
    vec3 result = (ambient*attenuation + diffuse*attenuation + specular*attenuation) * vec3(1,1,1);//* ourColor;
    FragColor = vec4(result, 1.0);
} 