#pragma once

#define callBase(base, name, inP) \
    Make name inP requires std::derived_from<T, base>

#define callBaseWithReqs(base, name, inP, reqs) \
    Make name inP requires (std::derived_from<T, base> && reqs)

#define call(base, name, method) \
    callBase(base, name, ()) { \
        this->m_obj->method(); \
        return *this; \
    }
#define callSN(base, name) \
    callBase(base, name, ()) { \
        this->m_obj->name(); \
        return *this; \
    }

#define call1(base, name, method, type1, arg1) \
    callBase(base, name, (type1 arg1)) { \
        this->m_obj->method(std::forward<type1>(arg1)); \
        return *this; \
    }
#define call1SN(base, name, type1, arg1) \
    callBase(base, name, (type1 arg1)) { \
        this->m_obj->name(arg1); \
        return *this; \
    }

#define call2(base, name, method, type1, arg1, type2, arg2) \
    callBase(base, name, (type1 arg1, type2 arg2)) { \
        this->m_obj->method(std::forward<type1>(arg1), std::forward<type2>(arg2)); \
        return *this; \
    }

#define call2SN(base, name, type1, arg1, type2, arg2) \
    callBase(base, name, (type1 arg1, type2 arg2)) { \
        this->m_obj->name(std::forward<type1>(arg1), std::forward<type2>(arg2)); \
        return *this; \
    }

#define call2Comb(base, name, method, type1, arg1, type2, arg2, toType) \
    callBase(base, name, (type1 arg1, type2 arg2)) { \
        this->m_obj->method(toType{std::forward<type1>(arg1), std::forward<type2>(arg2)}); \
        return *this; \
    }

#define call3(base, name, method, type1, arg1, type2, arg2, type3, arg3) \
    callBase(base, name, (type1 arg1, type2 arg2, type3 arg3)) { \
        this->m_obj->method(std::forward<type1>(arg1), std::forward<type2>(arg2), std::forward<type3>(arg3)); \
        return *this; \
    }

#define call4Comb(base, name, method, type1, arg1, type2, arg2, type3, arg3, type4, arg4, toType) \
    callBase(base, name, (type1 arg1, type2 arg2, type3 arg3, type4 arg4)) { \
        this->m_obj->method(toType{std::forward<type1>(arg1), std::forward<type2>(arg2), std::forward<type3>(arg3), std::forward<type4>(arg4)}); \
        return *this; \
    }

#define callP(base, name, method, inP, outP) \
    callBase(base, name, inP) { \
        this->m_obj->method outP; \
        return *this; \
    }

#define callPWithReqs(base, name, method, inP, outP, reqs) \
    callBaseWithReqs(base, name, inP, reqs) { \
        this->m_obj->method outP; \
        return *this; \
    }

#define callPSN(base, name, inP, outP) \
    callBase(base, name, inP) { \
        this->m_obj->name outP; \
        return *this; \
    }

#define withOther(base, name, type, paramName, member) \
    callBase(base, name, (geode::Function<void(Make<type> paramName)> callback)) { \
        /* ReSharper disable once CppTemplateArgumentsCanBeDeduced */ \
        /* No, they in fact cannot be deduced. Thanks. */ \
        callback(Make<type>(member)); \
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
        this->m_obj->member = outP; \
        return *this; \
    }