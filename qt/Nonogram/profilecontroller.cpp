#include "ProfileController.h"
#include "CSVUserDAO.h"
#include "csvscoredao.h"

ProfileController::ProfileController(QObject *parent)
    : QObject(parent) {}

void ProfileController::registerUser(const QString &name, int imageNumber) {
    if (name.isEmpty()) {
        emit registrationFailed(QString("Name cannot be blank"));
        return;
    }

    CSVUserDAO userDAO(QString("users.csv"));
    int newUserId = userDAO.getNextUserId();
    User newUser(newUserId, name, imageNumber, 0, 0, 0); // Adjust parameters as needed
    userDAO.insert(newUser);
    emit registrationSucceeded();
}

void ProfileController::updateTotalTimePlayed(int currentUserId, int timeElapsed)
{
    CSVUserDAO userDAO("users.csv");
    User user = userDAO.getUserById(currentUserId);

    qint64 totalTimeElapsed = user.getTotalTimePlayed() + timeElapsed;
    qDebug() << user.getTotalTimePlayed() << timeElapsed << "=" << totalTimeElapsed;
    user.setTotalTimePlayed(totalTimeElapsed);

    CSVScoreDAO scoreDAO("score.csv");
    qint64 fastestTimePlayed = scoreDAO.getMinTimeForUser(user.getName());
    qDebug() << "Fastest Completed: " << fastestTimePlayed;
    user.setFastestCompleted(fastestTimePlayed);

    int totalLevelCompleted = scoreDAO.getCountLevelForUser(user.getName());
    qDebug() << "Total Level Completed: " << totalLevelCompleted;
    user.setLevelCompleted(totalLevelCompleted);

    userDAO.updateUser(user);
}

void ProfileController::confirmUserDeletion(int userId)
{
    CSVUserDAO userDAO("users.csv");
    userDAO.deleteUser(userId);
}

void ProfileController::getCurrentUser(int userId)
{
    CSVUserDAO userDAO("users.csv");
    User user = userDAO.getUserById(userId);
    emit returnCurrentUser(user);
}
