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


vec3 calculateDirectionalLight(){
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    
    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
   
    
    float spec = pow(max(dot(viewDir, reflectDir), 0), 40);
    //if(dot(norm, lightDir) < 0){
    //    spec = 0.0;
    //}
    vec3 specular = specularStrength * spec * lightColor;  
    return(ambient+diffuse+specular);
        
}
vec3 calculatePointLight(){
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    
    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
   
    
    float spec = pow(max(dot(viewDir, reflectDir), 0), 40);
    //if(dot(norm, lightDir) < 0){
    //    spec = 0.0;
    //}
    vec3 specular = specularStrength * spec * lightColor;  

    float distance = length(lightPos - FragPos);
    float attenuation = 1.0 / (1.0f + 0.09f * distance + 0.032f * (distance * distance));     
        
    return (ambient*attenuation + diffuse*attenuation + specular*attenuation);
}
void main()
{
    //amb
    vec3 result = calculateDirectionalLight() * vec3(1,1,0);//* ourColor;
    result += calculatePointLight();
    FragColor = vec4(result, 1.0);
} 