#include <iostream>

#include <memory>
#include <vector>

#include "EditorView.h"
#include "EditorModel.h"
#include "EditorController.h"

int main() {

    auto model = std::make_shared<EditorModel>();
    auto controller = std::make_shared<EditorController>(model);
    auto view = std::make_shared<EditorView>(model, controller);


    view->new_document_click();
    view->create_line_click({0,0}, {1,1});
    view->create_rectangle_click({0,0}, {1,1});
    view->create_triangle_click({0,1}, {0.5,1.5}, {1,1});
    view->create_circle_click({0.5,0.5}, 0.5);

    std::cout << "Figures is saved to a file." << std::endl;
    view->export_to_file_click();
    std::cout << "Delete figure with id = 2" << std::endl;
    view->delete_figure_click(2);
    std::cout << "Figures is loading from a file." << std::endl;
    view->import_from_file_click();


    return 0;
}
