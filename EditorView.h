#ifndef EDITORVIEW_H
#define EDITORVIEW_H

#include <memory>
#include <utility>

#include "IFigure.h"
#include "EditorModel.h"
#include "EditorController.h"

/// <summary>
/// Class EditorView (MVC).
/// </summary>
class EditorView {
public:
    EditorView(std::shared_ptr<EditorModel> model, std::shared_ptr<EditorController> controller) :
    _model(std::move(model)), _controller(std::move(controller)) {};

    void new_document_click();
    void export_to_file_click();
    void import_from_file_click();
    void create_line_click(const Point& a, const Point& b);
    void create_rectangle_click(const Point& a, const Point& b);
    void create_triangle_click(const Point& a, const Point& b, const Point& c);
    void create_circle_click(const Point& a, float r);
    void delete_figure_click(std::size_t id);

private:
    void update_view();
    static void draw_figure(const std::shared_ptr<IFigure>& figure);
    static void clear_view();

private:
    std::shared_ptr<EditorModel> _model;
    std::shared_ptr<EditorController> _controller;
};


#endif //EDITORVIEW_H
