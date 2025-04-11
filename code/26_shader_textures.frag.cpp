#include <stdint.h>
#include <shady.h>
#include <nasl.h>

using namespace vcc;
using namespace nasl;

descriptor_set(0) descriptor_binding(1) uniform_constant sampler2D texSampler;

location(0) input native_vec3 fragColor;
location(1) input native_vec2 fragTexCoord;

location(0) output native_vec4 outColor;

extern "C" {

float boo(native_vec4* p, float* f) {
    native_vec4 w;
    __builtin_memcpy(&w, p, 16);
    *f = w.x;
    return w.z;
}

fragment_shader void main() {
    //auto v = vec4(fragColor.x, fragColor.y, fragColor.z, 1.0f);
    //v.x = fragColor.x;
    //outColor = native_vec4(v.arr[0]);
    //outColor = (vec4) { fragColor.x, fragColor.y, fragColor.z, 1.0f };
    outColor = texture2D(texSampler, fragTexCoord) * (vec4) { fragColor.x, fragColor.y, fragColor.z, 1.0f };
    
    /*native_vec4 v = { fragColor.x, fragColor.y, fragColor.z, 1.0f };
    native_vec4 w;
    __builtin_memcpy(&w, &v, 16);
    outColor = w;*/
    
    /*float j, k;
    native_vec4 v = { fragColor.x, fragColor.y, fragColor.z, 1.0f };
    float f = boo(&v, &j);
    native_vec4 w = { f, j, f, 1.0f };
    outColor = w;*/
    
    /*native_vec4 w = { fragColor.x, fragColor.y, fragColor.z, 1.0f };
    outColor = *((vec4*)(&w));*/
    
    /*native_vec4 w = { fragColor.x, fragColor.y, fragColor.z, 1.0f };
    native_vec4 u = { 1.0f, 0.0f, 0.0f, 1.0f };
    native_vec4 v = { 1.0f, 1.0f, 1.0f, 1.0f };
    v = u;
    __builtin_memcpy(&v, &w, 16);
    outColor = v;*/
}

}
