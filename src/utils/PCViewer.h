#ifndef SOFACV_COMMON_PCVIEWER_H
#define SOFACV_COMMON_PCVIEWER_H

#include "SofaCVPlugin.h"
#include "ImplicitDataEngine.h"

namespace sofacv
{
namespace utils
{
class SOFA_SOFACV_API PCViewer : public ImplicitDataEngine
{
	typedef sofa::defaulttype::Vector3 Vector3;
	typedef sofa::defaulttype::Vec<3, uint8_t> Vec3b;

 public:
    SOFA_CLASS(PCViewer, ImplicitDataEngine);

 public:
  PCViewer();
  virtual ~PCViewer();

  virtual void init() override;
  virtual void Update() override;
	void computeBBox(const sofa::core::ExecParams*, bool);
  virtual void draw(const sofa::core::visual::VisualParams*) override;
  virtual void reinit();

	sofa::Data<double> d_size;
	// INPUTS
	sofa::Data<sofa::helper::vector<Vector3> > d_positions;
	sofa::Data<sofa::helper::vector<Vec3b> > d_colors;
    sofa::Data<Vec3b> d_color;

 private:
	std::vector<sofa::defaulttype::Vec4f> m_colors;
	std::vector<Vector3> m_positions;
};

}  // namespace common
}  // namespace sofacv
#endif  // SOFACV_COMMON_PCVIEWER_H