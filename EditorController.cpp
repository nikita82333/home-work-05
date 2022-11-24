#include "EditorController.h"

void EditorController::new_document() {
    _model->new_document();
    _last_action = Action::NewDocument;
}

void EditorController::export_to_file() {
    _model->export_to_file();
}

void EditorController::import_from_file() {
    _model->import_from_file();
    _last_action = Action::OpenDocument;
}

void EditorController::delete_figure(std::size_t id) {
    _model->delete_figure(id);
    _last_action = Action::RemoveFigure;
    _last_id = id;
}

Action EditorController::get_last_action() {
    return _last_action;
}

std::size_t EditorController::get_last_id() const {
    return _last_id;
}



