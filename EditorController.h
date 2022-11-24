#ifndef EDITORCONTROLLER_H
#define EDITORCONTROLLER_H

#include <memory>
#include <utility>

#include "EditorModel.h"
#include "IFigure.h"

enum class Action {
    AddFigure,
    RemoveFigure,
    NewDocument,
    OpenDocument
};

/// <summary>
/// Class EditorController (MVC).
/// </summary>
class EditorController {
public:
    explicit EditorController(std::shared_ptr<EditorModel> model) :
    _model(std::move(model)), _last_action(Action::NewDocument), _last_id(0) {};

    void new_document();
    void export_to_file();
    void import_from_file();
    template <typename T>
    void add_figure(const T& figure);
    void delete_figure(std::size_t id);
    Action get_last_action();
    [[nodiscard]] std::size_t get_last_id() const;

private:
    std::shared_ptr<EditorModel> _model;
    Action _last_action;
    std::size_t _last_id;
};


template <typename T>
void EditorController::add_figure(const T& figure) {
    _last_action = Action::AddFigure;
    _last_id = _model->add_figure(figure);
}


#endif //EDITORCONTROLLER_H