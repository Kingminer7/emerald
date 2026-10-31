#pragma once

#define callBase(base, name, inP) \
    Make name inP requires std::derived_from<T, base>

#define callBaseTo(base, name, inP, retT) \
    Make<retT> name inP requires std::derived_from<T, base>

#define callBaseWithReqs(base, name, inP, reqs) \
    Make name inP requires (std::derived_from<T, base> && reqs)

#define call(base, name, method) \
    callBase(base, name, ()) { \
        if (this->m_obj) this->m_obj->method(); \
        return *this; \
    }

#define callP(base, name, method, inP, outP) \
    callBase(base, name, inP) { \
        if (this->m_obj) this->m_obj->method outP; \
        return *this; \
    }

#define callPWithReqs(base, name, method, inP, outP, reqs) \
    callBaseWithReqs(base, name, inP, reqs) { \
        if (this->m_obj) this->m_obj->method outP; \
        return *this; \
    }

#define withOther(base, name, type, paramName, member) \
    callBase(base, name, (geode::Function<void(Make<type> paramName)> callback)) { \
        /* ReSharper disable once CppTemplateArgumentsCanBeDeduced */ \
        /* No, they in fact cannot be deduced. Thanks. */ \
        if (m_obj) callback(Make<type>(member)); \
        return *this; \
    }


// just for syntax stuff, the static is gonna be done in the class
#define createP(base, name, method, inP, outP) \
    callBase(base, name, inP) { \
        return Make(T::method outP); \
    }

#define createPWithReqs(base, name, method, inP, outP, reqs) \
    callBaseWithReqs(base, name, inP, reqs) { \
        return Make(T::method outP); \
    }

// members! cause robtop doesnt make getters/setters sometimes
// looking at you ccmise m_iconType
#define setMember(base, name, member, inP, outP) \
    callBase(base, name, inP) { \
        if (this->m_obj) this->m_obj->member = outP; \
        return *this; \
    }