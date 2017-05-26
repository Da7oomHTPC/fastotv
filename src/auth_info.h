/*  Copyright (C) 2014-2017 FastoGT. All right reserved.

    This file is part of FastoTV.

    FastoTV is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoTV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoTV. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>

#include "client_server_types.h"

struct json_object;

#define AUTH_INFO_LOGIN_FIELD "login"
#define AUTH_INFO_PASSWORD_FIELD "password"

namespace fasto {
namespace fastotv {

struct AuthInfo {
  AuthInfo();
  AuthInfo(const std::string& login, const std::string& password);

  bool IsValid() const;

  static json_object* MakeJobject(const AuthInfo& ainf);  // allocate json_object
  static AuthInfo MakeClass(json_object* obj);            // pass valid json obj

  login_t login;  // unique
  std::string password;
};

inline bool operator==(const AuthInfo& lhs, const AuthInfo& rhs) {
  return lhs.login == rhs.login && lhs.password == rhs.password;
}

inline bool operator!=(const AuthInfo& x, const AuthInfo& y) {
  return !(x == y);
}

}  // namespace fastotv
}  // namespace fasto