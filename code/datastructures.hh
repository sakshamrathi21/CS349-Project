#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include "common-headers.h"
extern int current_timestamp;

class IndexEntry {
    private:
    int createTime;
    int numAccesses;
    public:
    std::string tableName;
    std::string attributeName;
    std::set<std::string>* setOfAttributes;
    std::string indexName;

    IndexEntry(const std::string&);
    IndexEntry(const std::string&, std::set<std::string>* const);
    bool operator<(const IndexEntry& other);
    friend std::ostream& operator<<(std::ostream& , const IndexEntry&);
    void setCreateTime(const int&);
    int getCreateTime();
    void setNumOfAccesses(const int&);
    int getNumOfAccesses();
};

extern std::set<pid_t> existing_child_processes;
bool indexExists(const std::string&, const std::set<std::string>* const);
void updateIndexEntry(const std::string& ,std::set<std::string>* const);
extern std::vector<IndexEntry*> indices;
#endif