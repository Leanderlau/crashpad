// Copyright 2014 The Crashpad Authors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CRASHPAD_UTIL_MAC_XATTR_H_
#define CRASHPAD_UTIL_MAC_XATTR_H_

#include <time.h>

#include <string>

#include "base/files/file_path.h"
#include "base/strings/string_piece.h"

namespace crashpad {

//! \brief Reads an extended attribute on a file.
//!
//! \param[in] file The path to the file.
//! \param[in] name The name of the extended attribute to read.
//! \param[out] value The value of the attribute.
//!
//! \return `true` if the read was successful, with \a value filled in. `false`
//!     on error, with a message logged.
bool ReadXattr(const base::FilePath& file,
               const base::StringPiece& name,
               std::string* value);

//! \brief Writes an extended attribute on a file.
//!
//! \param[in] file The path to the file.
//! \param[in] name The name of the extended attribute to write.
//! \param[in] value The value of the attribute.
//!
//! \return `true` if the write was successful. `false` on error, with a message
//!     logged.
bool WriteXattr(const base::FilePath& file,
                const base::StringPiece& name,
                const std::string& value);

//! \copydoc ReadXattr
//!
//! Only the values `"0"` and `"1"`, for `false` and `true` respectively, are
//! valid conversions.
bool ReadXattrBool(const base::FilePath& file,
                   const base::StringPiece& name,
                   bool* value);

//! \copydoc WriteXattr
bool WriteXattrBool(const base::FilePath& file,
                    const base::StringPiece& name,
                    bool value);

//! \copydoc ReadXattr
bool ReadXattrInt(const base::FilePath& file,
                  const base::StringPiece& name,
                  int* value);

//! \copydoc WriteXattr
bool WriteXattrInt(const base::FilePath& file,
                   const base::StringPiece& name,
                   int value);

//! \copydoc ReadXattr
bool ReadXattrTimeT(const base::FilePath& file,
                    const base::StringPiece& name,
                    time_t* value);

//! \copydoc WriteXattr
bool WriteXattrTimeT(const base::FilePath& file,
                     const base::StringPiece& name,
                     time_t value);

}  // namespace crashpad

#endif  // CRASHPAD_UTIL_MAC_XATTR_H_
