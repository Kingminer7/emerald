#pragma once

/// Gives the popup standard IDs, with a mod id that you specify.
/// Useful for popups created by libraries (such as minilayer) or just templated popups in api headers.
#define GivePopupStandardIdsWithModId(className, spr) \
    this->setID(spr #className); \
    if (m_title) m_title->setID("title-label"); \
    m_mainLayer->setID("main-layer"); \
    m_buttonMenu->setID("close-menu"); \
    m_closeBtn->setID("close-btn"); \
    m_bgSprite->setID("background")

/// Gives the popup standard IDs, using the mod id from _spr.
#define GivePopupStandardIds(className) GivePopupStandardIdsWithModId(className, ""_spr)

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
constexpr auto operator""_gspr() {
    return Str.buffer;
}