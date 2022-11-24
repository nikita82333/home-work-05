#include "EditorView.h"

void EditorView::update_view() {
    //
    Action action = _controller->get_last_action();
    if (action == Action::RemoveFigure || action == Action::NewDocument || action == Action::OpenDocument) {
        clear_view();
        for (const auto& [current_id, figure] : _model->get_figures()) {
            draw_figure(figure);
        }
    } else if (action == Action::AddFigure) {
        draw_figure(_model->get_figures().find(_controller->get_last_id())->second);
    }
    //
}

void EditorView::draw_figure(const std::shared_ptr<IFigure>& figure) {
    //
    std::cout << "A figure is drawn: ";
    figure->draw();
    //
}

void EditorView::clear_view() {
    //
    std::cout << "View is cleared." << std::endl;
    //
}

void EditorView::new_document_click() {
    _controller->new_document();
    clear_view();
}

void EditorView::export_to_file_click() {
    _controller->export_to_file();
}

void EditorView::import_from_file_click() {
    _controller->import_from_file();
    update_view();
}

void EditorView::create_line_click(const Point &a, const Point &b) {
    _controller->add_figure(Line(a, b));
    update_view();
}

void EditorView::create_rectangle_click(const Point &a, const Point &b) {
    _controller->add_figure(Rectangle(a, b));
    update_view();
}

void EditorView::create_triangle_click(const Point &a, const Point &b, const Point &c) {
    _controller->add_figure(Triangle(a, b, c));
    update_view();
}

void EditorView::create_circle_click(const Point &a, float r) {
    _controller->add_figure(Circle(a, r));
    update_view();
}

void EditorView::delete_figure_click(std::size_t id) {
    _controller->delete_figure(id);
    update_view();
}
