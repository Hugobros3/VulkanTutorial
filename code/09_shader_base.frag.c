#include <stdint.h>
#include <shady.h>

location(0) input vec3 fragColor;

location(0) output vec4 outColor;

fragment_shader void main() {
    outColor = (vec4) { fragColor[0], fragColor[1], fragColor[2], 1.0f };
    //outColor = (vec4) { gl_FragCoord[0] / 1024, gl_FragCoord[1] / 1024, 1.0f, 1.0f };
}
