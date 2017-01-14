#ifndef CONSTANT_H
#define CONSTANT_H
#include <QString>
namespace radarValue {
    const int AZIMUTH_MAX_VALUE = 360;
    const int AZIMUTH_MIN_VALUE = 0;
    const int POWER_MAX_VALUE = 500;
    const int POWER_MIN_VALUE = 300;

}
namespace uiValue {
    const int LABELMAX_WIDTH_1 = 50;
    const int LABELMAX_WIDTH_2 = 150;
}
namespace statusMessage {
    const QString UNGRAB_MESSAGE = "ungrab the plot...";
    const QString GRAB_MESSAGE = "grab the plot...";
    const QString UNZOOM_MESSAGE = "unzoom the plot...";
    const QString SETPARAME_MESSAGE = "set targets paramters...";
    const QString STARTSCAN_MESSAGE = "start to  scan...";
    const QString STOPSCAN_MESSAGE = "stop  scanning...";

}
namespace imagePath {
    const QString grabPath = ":/res/image/grab.jpg";
    const QString startPath = ":/res/image/start.jpg";
    const QString stopPath = ":/res/image/stop.jpg";
    const QString paramePath = ":/res/image/parame.jpg";
    const QString unzoomPath = ":/res/image/unzoom.jpg";

}
class constant
{
public:
    constant();
};

#endif // CONSTANT_H
