#include <stdint.h>

#define fragment_shader __attribute__((annotate("shady::entry_point::Fragment")))

#define location(i) __attribute__((annotate("shady::location::"#i)))

#define input __attribute__((address_space(389)))
#define output __attribute__((address_space(390)))

typedef uint32_t uvec4 __attribute__((ext_vector_type(4)));
typedef float vec4 __attribute__((ext_vector_type(4)));

typedef uint32_t uvec3 __attribute__((ext_vector_type(3)));
typedef float vec3 __attribute__((ext_vector_type(3)));

__attribute__((annotate("shady::builtin::FragCoord")))
input vec4 fragCoord;

location(0) input vec3 fragColor;

location(0) output vec4 outColor;

fragment_shader void main() {
    outColor = (vec4) { fragColor[0], fragColor[1], fragColor[2], 1.0f };
    //outColor = (vec4) { fragCoord[0] / 1024, fragCoord[1] / 1024, 1.0f, 1.0f };
}