//
// Created by Marco Bassaletti on 24-02-21.
//

#ifndef OWNPASS_CATEGORY_H
#define OWNPASS_CATEGORY_H

#include "Group.h"
#include <list>
#include <optional>

class Category {
public:
    Category() = default;
    Category(Category& other) = default;
    Category(Category&& other) noexcept : groups{} { *this = std::move(other); }
    Category(std::string& name) : name{ name } {}
    ~Category() = default;

    Category& operator=(Category&& other)  noexcept {
        groups.clear();
        groups = std::move(other.groups);
        return *this;
    }
    [[nodiscard]] const std::string& get_name() const { return name; }
    [[nodiscard]] const std::list<Group>& get_groups() const { return groups; }
    Category& add_group(Group& group);
    std::optional<Group> find_group(std::string& group_name);
    std::list<std::reference_wrapper<Group>> find_groups(std::string& search);
    Category& remove_group(Group& group);
    Category& remove_group(std::string& group_name);
private:
    std::string name;
    std::list<Group> groups;
};


#endif //OWNPASS_CATEGORY_H
