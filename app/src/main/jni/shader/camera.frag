const char* camera_play_frag = STRINGIFY(

precision mediump float;

uniform sampler2D   u_Texture;
varying vec2        v_TextCoord;

void main()
{
	gl_FragColor = texture2D(u_Texture, v_TextCoord);
}
);