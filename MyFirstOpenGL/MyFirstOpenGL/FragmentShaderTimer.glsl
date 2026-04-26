#version 440 core

out vec4 fragColor;

uniform float Timer;


void main(){

	fragColor = vec4 (1.0,0.0,0.0,1.0);

	if(Timer < 2.0f){
	
		fragColor = vec4 (1.0,0.0,0.0,1.0);
	}
	else if(Timer < 4.0f && Timer >= 2.0f){
	
		fragColor = vec4 (0.0,1.0,0.0,1.0);
	}
	else if(Timer < 6.0f && Timer >= 4.0f){
	
		fragColor = vec4 (0.0,0.0,1.0,1.0);
	}
	

}