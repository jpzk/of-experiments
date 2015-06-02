#version 150
 
uniform sampler2DRect image;

in vec2 varyingtexcoord; 
out vec4 outputColor;
 
void main()
{
    vec4 planar = texture(image, gl_FragCoord.xy);
    vec4 reflect = texture(image, varyingtexcoord);

    outputColor  = mix(planar, reflect, 0.8);

}
