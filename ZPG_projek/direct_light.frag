#version 330
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
in vec3 ourColor;
  
uniform float ambientStrength;
uniform vec3 lightColor;

uniform vec3 lightPos; 

uniform vec3 viewPos; 

//Pointlight
uniform vec3 light_Pos[10];

//DirectionalLight
uniform vec3 direct_Light_Direct;

//Spot light 
uniform vec3 lightPosition_var;
uniform vec3 lightDirection_var;
uniform float cutOff_var;
uniform float outerCut_var;
uniform float flashlight_Strength;
//uniform vec3 objectColor;


//texture
uniform sampler2D texture_Sphere;


vec3 calculateDirectionalLight(vec3 lightDir_var){
    vec3 ambient = ambientStrength * lightColor;
  	
    //vec3 norm_tmp = texture(texture_Sphere, vec2(Norm));
    // diffuse 
    vec3 norm = normalize(Normal);

    vec3 lightDir = normalize(lightDir_var);
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
vec3 calculatePointLight(vec3 light_Pos){
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light_Pos - FragPos);
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

    float distance = length(light_Pos - FragPos);
    float attenuation = 1.0 / (1.0f + 0.01f * distance + 0.5f * (distance * distance));     
        
    return (ambient*attenuation + diffuse*attenuation + specular*attenuation);//* vec3(1,1,0);
}
vec3 calculateSpotLight(vec3 lightPosition_var, vec3 lightDirection_var, float cutOff_var, float outerCut_var, float flashlight_strength){
     vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition_var - FragPos);
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

    float distance = length(lightPosition_var - FragPos);
    float attenuation = 1.0 / (1.0f + 0.00f * distance + 0.1f * (distance * distance));     

    float theta = dot(lightDir, normalize(-lightDirection_var)); 
    float epsilon = cutOff_var - outerCut_var;
    float intensity = clamp((theta - outerCut_var) / epsilon, 0.0, 1.0);
        
    return (ambient*attenuation*intensity*flashlight_Strength + diffuse*attenuation*intensity*flashlight_Strength + specular*attenuation*intensity*flashlight_Strength);//* vec3(1,1,0);

}
void main()
{
    vec3 result = vec3(0,0,0);
    //amb
    if(direct_Light_Direct != vec3(0,0,0)){
        result = calculateDirectionalLight(direct_Light_Direct);// * vec3(1,1,0);//* ourColor;
    }
    //vec3 result = vec3(0,0,0);
    for(int i=0;i<10;i++){
        if(light_Pos[i] != vec3(0,0,0)){

        result += calculatePointLight(light_Pos[i]);
        
        }
    }
    result+=calculateSpotLight(lightPosition_var, lightDirection_var, cutOff_var,outerCut_var,flashlight_Strength);
    //result*= vec3(1,1,0);
    FragColor = vec4(result, 1.0) * texture(texture_Sphere, vec2(Normal));
    //FragColor = texture(texture_Sphere, vec2(FragPos));
} 