#ifndef WFREST_HTTPCOOKIE_H_
#define WFREST_HTTPCOOKIE_H_

#include <string>
#include "wfrest/Timestamp.h"

namespace wfrest
{

// https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Set-Cookie
// https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Cookie
// https://developer.mozilla.org/en-US/docs/Web/HTTP/Cookies

class HttpCookie
{
public:
    // Check if the cookie is empty
    operator bool() const
    { return (!key_.empty()) && (!value_.empty()); }

    std::string dump() const;

public:
    void set_key(const std::string &key)
    { key_ = key; }

    void set_key(const std::string &&key)
    { key_ = std::move(key); }

    void set_value(const std::string &value)
    { value_ = value; }

    void set_value(std::string &&value)
    { value = std::move(value); }

    void set_domain(const std::string &domain)
    { domain_ = domain; }

    void set_domain(std::string &&domain)
    { domain_ = std::move(domain); }

    void set_path(const std::string &path)
    { path_ = path; }

    void set_path(std::string &&path)
    { path_ = std::move(path); }  

    void set_expires(const Timestamp &expires)
    { expires_ = expires; }

    void set_max_age(int max_age) 
    { max_age_ = max_age; }

    void set_secure(bool secure)
    { secure_ = secure; }

    void set_http_only(bool http_only)
    { http_only_ = http_only; }

public:
    const std::string &key() const 
    { return key_; }
    
    const std::string &value() const
    { return value_; }

    const std::string &domain() const 
    { return domain_; }

    const std::string &path() const 
    { return path_; }

    const Timestamp &expires() const 
    { return expires_; }

    int max_age() const 
    { return max_age_; }

    bool is_secure()
    { return secure_; }

    bool is_http_only()
    { return http_only_; }

public:
    HttpCookie(const std::string &key, const std::string &value)
        : key_(key), value_(value) 
    {}

    HttpCookie(const std::string &&key, const std::string &&value)
        : key_(std::move(key)), value_(std::move(value))
    {}

    HttpCookie() = default;

private:
    std::string key_;
    std::string value_;
    std::string domain_;
    std::string path_;
    Timestamp expires_;
    int max_age_ = 0;
    bool secure_ = false;
    bool http_only_ = false;
};

} // namespace wfrest




#endif // WFREST_HTTPCOOKIE_H_