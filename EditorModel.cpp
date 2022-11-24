#include "EditorModel.h"

void EditorModel::new_document() {
    _figures.clear();
    std::cout << "New document is created." << std::endl;
}

void EditorModel::export_to_file() {
    std::fstream file(_file_name, std::ios::out | std::ios::binary);
    if (file.is_open()) {
        for (const auto& [id, figure] : _figures) {
            int type = figure->get_type();
            file.write((char*)&type, sizeof(int));
            figure->save(file);
        }
        file.close();
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
}

void EditorModel::import_from_file() {
    std::fstream file(_file_name, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        _figures.clear();
        int type;
        while (file.read((char*)&type, sizeof(int))) {
            switch (type) {
                case TypeID::Line:
                    add_figure(Line(file));
                    break;
                case TypeID::Rectangle:
                    add_figure(Rectangle(file));
                    break;
                case TypeID::Triangle:
                    add_figure(Triangle(file));
                    break;
                case TypeID::Circle:
                    add_figure(Circle(file));
                    break;
                default:
                    break;
            }
        }
        file.close();
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
}

void EditorModel::delete_figure(std::size_t id) {
    _figures.erase(id);
}

figure_storage EditorModel::get_figures() {
    return _figures;
}
