#version 330 core

out vec4 FragColor;


uniform float u_time;
uniform float u_pulse;
uniform float u_glow;
uniform float u_distortion;
uniform vec2  u_resolution;


float noise(vec2 uv)
{
    return fract(sin(dot(uv, vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
    vec2 uv = gl_FragCoord.xy / u_resolution.xy;
    uv -= 0.5;


    uv.x *= u_resolution.x / u_resolution.y;

    float wave = sin(uv.y * 8.0 + u_time * 0.6);
    uv.x += wave * u_distortion;


    vec3 baseDark = vec3(0.02, 0.03, 0.07);
    vec3 baseGlow = vec3(0.1, 0.15, 0.35);

    float grad = length(uv) * 1.6;
    grad = clamp(1.0 - grad, 0.0, 1.0);

    vec3 color = mix(baseDark, baseGlow, grad);


    color += u_pulse * vec3(0.15, 0.2, 0.4);


    color *= 1.0 + u_glow * 0.8;

    float n = noise(gl_FragCoord.xy + u_time * 10.0);
    color += (n - 0.5) * 0.02;

    FragColor = vec4(color, 1.0);
}
