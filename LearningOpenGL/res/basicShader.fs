#version 120

//out vec4 FragColor;
uniform sampler2D diffuse;

varying vec2 texCoord0;

varying vec3 normal0;


void main()
{
	gl_FragColor = texture2D(diffuse, texCoord0)
		* clamp(dot(-vec3(1,0,0), normal0), 0.0, 1.0);
	
}