/*
 *   Copyright (C) 2020 Nippon Telegraph and Telephone Corporation.

 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at

 *   http://www.apache.org/licenses/LICENSE-2.0

 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#ifndef LINEAIRDB_CONCURRENT_TABLE_H
#define LINEAIRDB_CONCURRENT_TABLE_H

#include <lineairdb/config.h>

#include <functional>
#include <string>
#include <string_view>

#include "concurrent_point_index_base.h"
#include "types.h"

namespace LineairDB {
namespace Index {

class ConcurrentTable {
 public:
  ConcurrentTable(Config config             = Config(),
                  WriteSetType recovery_set = WriteSetType());
  ~ConcurrentTable();

  DataItem* Get(const std::string_view key);
  DataItem* GetOrInsert(const std::string_view key);
  bool Put(const std::string_view key, const DataItem& value);
  DataItem* InsertIfNotExist(const std::string_view key);

 private:
  std::unique_ptr<ConcurrentPointIndexBase> container_;
};
}  // namespace Index
}  // namespace LineairDB

#endif /* LINEAIRDB_CONCURRENT_TABLE_H */
