#pragma once

// Borrowed from Geode and altered for my use case
namespace emerald::internal {
    template <size_t N>
    struct StringConcatGeodeSlash {
        static constexpr size_t extra = sizeof("geode.loader");
        char buffer[extra + N]{};
        constexpr StringConcatGeodeSlash(const char (&pp)[N]) {
            char id[] = "geode.loader";
            for (int i = 0; i < sizeof(id); ++i) {
                buffer[i] = id[i];
            }
            buffer[extra - 1] = '/';
            for (int i = 0; i < N; ++i) {
                buffer[extra + i] = pp[i];
            }
        }
    };
}

template <emerald::internal::StringConcatGeodeSlash Str>
constexpr auto operator""_gode() {
    return Str.buffer;
}