#ifndef EDITORLEVEL_H
#define EDITORLEVEL_H

#include "level.h"

class EditorLevel : public Level
{
public:
    EditorLevel(
        const std::vector<std::vector<int>> &solutionGrid,
        const std::vector<std::vector<int>> &currentGrid,
        const std::vector<std::vector<int>> &rowHint,
        const std::vector<std::vector<int>> &colHint,
        const QString &difficulty,
        int size,
        const QString &levelName
    );

    void setSolutionTile(int row, int col, int val);
    void finalizeHint();

    QString getLevelName() const;
    void setLevelName(const QString &newLevelName);

    Level toLevel() const;

private:
    QString levelName;
};

#endif // EDITORLEVEL_H
