/*************************************************************************
	> File Name: json.h
	> Author: 隔壁老孙无敌 
	> Mail:1686169484@qq.com 
	> Created Time: Wed Sep  6 09:16:46 2023
 ************************************************************************/

#ifndef _JSON_H
#define _JSON_H

#include <vector>
#include <map>
#include <string>
using namespace std;
#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(My)

BEGINS(json)

class Json {
public:
    enum Type {
        json_null = 0,
        json_bool,
        json_int,
        json_double,
        json_string,
        json_array,
        json_object
    };

    Json();
    Json(bool value);
    Json(int value);
    Json(double value);
    Json(const char* value);
    Json(const std::string& value);
    Json(Type type);
    Json(const Json& other);

    operator bool();
    operator int();
    operator double();
    operator std::string();
    Json& operator[] (const char* key);
    Json& operator[] (int index);
    Json& operator[] (const string& key);
    void append(const Json& other);
    void operator= (const Json& other);
    bool operator== (const Json& other);
    bool operator!= (const Json& other);

    std::string str() const;

    void copy(const Json& other);
    void clear();

    typedef std::vector<Json>::iterator iterator;
    iterator begin() {
        return m_value.m_array->begin();
    }

    iterator end() {
        return m_value.m_array->end();
    }
    bool isNull() const { return m_type == json_null; }
    bool isBool() const { return m_type == json_bool; }
    bool isInt() const { return m_type == json_int; }
    bool isDouble() const { return m_type == json_double; }
    bool isString() const { return m_type == json_string; }
    bool isArray() const { return m_type == json_array; }
    bool isObject() const { return m_type == json_object; }
    bool asBool() const;
    int asInt() const;
    double asDouble() const;
    string asString() const;

    bool has(int index);
    bool has(const char* key);
    bool has(const string& key);
    
    void remove(int index);
    void remove(const char* key);
    void remove(const string& key);

private:
    union Value {
        bool m_bool;
        int m_int;
        double m_double;
        std::string* m_string;
        std::vector<Json>* m_array;
        std::map<std::string, Json>* m_object;

    };

    Type m_type;
    Value m_value;
};

ENDS(json)

ENDS(My)

#endif
