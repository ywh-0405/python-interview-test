#ifndef RVIZ_PLUGIN_TUTORIALS__TELEOP_PANEL_HPP_
#define RVIZ_PLUGIN_TUTORIALS__TELEOP_PANEL_HPP_

#include <rviz_common/panel.hpp>

class QLineEdit;
class QLabel;
class QPushButton;

namespace rviz_plugin_tutorials
{

class TeleopPanel : public rviz_common::Panel
{
  Q_OBJECT

public:
  explicit TeleopPanel(QWidget * parent = 0);

  void save(rviz_common::Config config) const override;
  void load(const rviz_common::Config & config) override;

private Q_SLOTS:
  void doAdd();
  void doMul();

private:
  QLineEdit * num1_editor_;
  QLineEdit * num2_editor_;
  QLineEdit * num3_editor_;
  QPushButton * add_button_;
  QPushButton * mul_button_;
  QLabel * result_label_;
};

}  // namespace rviz_plugin_tutorials

#endif  // RVIZ_PLUGIN_TUTORIALS__TELEOP_PANEL_HPP_