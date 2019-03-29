#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QObject>
#include <QPointF>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLWidget>
#include <QSharedPointer>
#include <QMatrix4x4>

#include "irisgl/src/irisglfwd.h"

namespace iris
{
	class CameraNode;
	class DefaultMaterial;
	class ForwardRenderer;
	class FullScreenQuad;
	class Mesh;
	class MeshNode;
	class Scene;
	class SceneNode;
	class Viewport;
	class ContentManager;
}

class CameraControllerBase;
class PlayerVrController;
class PlayerMouseController;
class QElapsedTimer;
class QTimer;

class PlayBack
{
	QMatrix4x4 savedCameraMatrix;
	CameraControllerBase* camController;
	PlayerVrController* vrController;
	PlayerMouseController* mouseController;

	iris::ForwardRendererPtr renderer;
	iris::ScenePtr scene;

	QTimer* updateTimer;
	QElapsedTimer* fpsTimer;
	QPointF prevMousePos;

	bool _isPlaying = false;
public:
	bool isScenePlaying() { return _isPlaying; }

	PlayBack();
	void init(iris::ForwardRendererPtr renderer);

	void setScene(iris::ScenePtr scene);
	void setController(CameraControllerBase* controller);

	void renderScene(iris::Viewport& viewport, float dt);

	void playScene();
	void pause();
	void stopScene();

	iris::ForwardRendererPtr getRenderer() { return renderer; }


	// callbacks from ui
	void mousePressEvent(QMouseEvent* evt);
	void mouseMoveEvent(QMouseEvent* evt);
	void mouseDoubleClickEvent(QMouseEvent* evt);
	void mouseReleaseEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent *event);

	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
};

#endif //PLAYBACK_H