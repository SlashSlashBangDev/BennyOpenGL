#version 120

//out vec4 FragColor;
uniform sampler2D diffuse;

varying vec2 texCoord0;


void main()
{
	gl_FragColor = texture2D(diffuse, texCoord0);
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}