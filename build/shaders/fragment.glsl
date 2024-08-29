#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform vec3 fogColor;
uniform float fogDensity;

void main() {
    vec4 texColor = texture(texture1, TexCoord);

    // Calculate fog effect
    float distance = length(gl_FragCoord.xy);
    float fogFactor = exp(-fogDensity * distance * distance);
    fogFactor = clamp(fogFactor, 0.0, 1.0);

    // Mix fog color with texture color
    FragColor = mix(vec4(fogColor, 1.0), texColor, fogFactor);
}
