#include <iostream>
#include <string>
#include <filesystem>

#include "rocksdb/db.h"
#include "rocksdb/options.h"
#include "rocksdb/slice.h"
#include "rocksdb/sst_file_reader.h"

using ROCKSDB_NAMESPACE::Iterator;
using ROCKSDB_NAMESPACE::Options;
using ROCKSDB_NAMESPACE::ReadOptions;
using ROCKSDB_NAMESPACE::Status;
using ROCKSDB_NAMESPACE::SstFileReader;

int main() {

    Options options;
    SstFileReader reader(options);
//    std::cout << std::filesystem::current_path() << std::endl;
    ROCKSDB_NAMESPACE::Status status = reader.Open("../000063.sst");
    assert(status.ok());

    reader.VerifyChecksum();

    ReadOptions ropts;
    std::unique_ptr<Iterator> iter(reader.NewIterator(ropts));
    iter->SeekToFirst();

    while (iter->Valid()) {
        std::cout << "Key: " << iter->key().ToString() << std::endl;
        iter->Next();
    }

    return 0;
}
