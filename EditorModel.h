#ifndef EDITORMODEL_H
#define EDITORMODEL_H

#include <map>
#include <utility>
#include <memory>
#include <fstream>
#include <string>

#include "IFigure.h"

using figure_storage = std::map<std::size_t, std::shared_ptr<IFigure>>;

/// <summary>
/// Class EditorModel (MVC).
/// </summary>
class EditorModel {
public:
    void new_document();
    void export_to_file();
    void import_from_file();
    template <typename T>
    std::size_t add_figure(const T& figure);
    void delete_figure(std::size_t id);
    figure_storage get_figures();

private:
    std::size_t _id {0};
    figure_storage _figures;
    std::string _file_name {"save.bin"};
};


template <typename T>
std::size_t EditorModel::add_figure(const T& figure) {
    _figures.emplace(_id, std::make_shared<T>(figure));
    std::size_t returning_id = _id;
    ++_id;
    return returning_id;
}


#endif //EDITORMODEL_H
