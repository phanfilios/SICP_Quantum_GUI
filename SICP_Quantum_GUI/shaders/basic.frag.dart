#version 330 core

out vec4 FragColor;

uniform float u_time;
uniform vec2 u_resolution;

void main()
{
    vec2 uv = gl_FragCoord.xy / u_resolution.xy;

    float pulse = sin(u_time * 0.5) * 0.1 + 0.5;

    vec3 colorOscuro = vec3(0.02, 0.02, 0.05);
    vec3 colorPulso  = vec3(0.05, 0.05, 0.1) * pulse;

    vec3 finalColor = mix(colorOscuro, colorPulso, uv.y);

    float noise = fract(sin(dot(uv, vec2(12.9898,78.233))) * 43758.5453);
    finalColor += (noise - 0.5) * 0.01;

    FragColor = vec4(finalColor, 1.0);
}