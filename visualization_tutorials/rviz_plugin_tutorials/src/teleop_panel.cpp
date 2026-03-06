#include "teleop_panel.hpp"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "pluginlib/class_list_macros.hpp"

namespace rviz_plugin_tutorials
{

TeleopPanel::TeleopPanel(QWidget * parent)
: rviz_common::Panel(parent)
{
  // 三个输入框
  num1_editor_ = new QLineEdit;
  num2_editor_ = new QLineEdit;
  num3_editor_ = new QLineEdit;

  num1_editor_->setPlaceholderText("请输入第1个数");
  num2_editor_->setPlaceholderText("请输入第2个数");
  num3_editor_->setPlaceholderText("请输入第3个数");

  // 两个按钮
  add_button_ = new QPushButton("加法");
  mul_button_ = new QPushButton("乘法");

  // 结果显示
  result_label_ = new QLabel("结果：");

  // 第一行
  QHBoxLayout * row1 = new QHBoxLayout;
  row1->addWidget(new QLabel("a:"));
  row1->addWidget(num1_editor_);

  // 第二行
  QHBoxLayout * row2 = new QHBoxLayout;
  row2->addWidget(new QLabel("b:"));
  row2->addWidget(num2_editor_);

  // 第三行
  QHBoxLayout * row3 = new QHBoxLayout;
  row3->addWidget(new QLabel("c:"));
  row3->addWidget(num3_editor_);

  // 按钮行
  QHBoxLayout * button_layout = new QHBoxLayout;
  button_layout->addWidget(add_button_);
  button_layout->addWidget(mul_button_);

  // 总布局
  QVBoxLayout * layout = new QVBoxLayout;
  layout->addLayout(row1);
  layout->addLayout(row2);
  layout->addLayout(row3);
  layout->addLayout(button_layout);
  layout->addWidget(result_label_);

  setLayout(layout);

  // 信号槽连接
  connect(add_button_, SIGNAL(clicked()), this, SLOT(doAdd()));
  connect(mul_button_, SIGNAL(clicked()), this, SLOT(doMul()));
}

void TeleopPanel::doAdd()
{
  bool ok1, ok2, ok3;
  double a = num1_editor_->text().toDouble(&ok1);
  double b = num2_editor_->text().toDouble(&ok2);
  double c = num3_editor_->text().toDouble(&ok3);

  if (!(ok1 && ok2 && ok3)) {
    result_label_->setText("结果：输入有误，请输入数字");
    return;
  }

  double result = a + b + c;
  result_label_->setText(QString("结果：%1").arg(result));
}

void TeleopPanel::doMul()
{
  bool ok1, ok2, ok3;
  double a = num1_editor_->text().toDouble(&ok1);
  double b = num2_editor_->text().toDouble(&ok2);
  double c = num3_editor_->text().toDouble(&ok3);

  if (!(ok1 && ok2 && ok3)) {
    result_label_->setText("结果：输入有误，请输入数字");
    return;
  }

  double result = a * b * c;
  result_label_->setText(QString("结果：%1").arg(result));
}

void TeleopPanel::save(rviz_common::Config config) const
{
  rviz_common::Panel::save(config);
  config.mapSetValue("num1", num1_editor_->text());
  config.mapSetValue("num2", num2_editor_->text());
  config.mapSetValue("num3", num3_editor_->text());
}

void TeleopPanel::load(const rviz_common::Config & config)
{
  rviz_common::Panel::load(config);

  QString num1, num2, num3;
  if (config.mapGetString("num1", &num1)) {
    num1_editor_->setText(num1);
  }
  if (config.mapGetString("num2", &num2)) {
    num2_editor_->setText(num2);
  }
  if (config.mapGetString("num3", &num3)) {
    num3_editor_->setText(num3);
  }
}

}  // namespace rviz_plugin_tutorials

PLUGINLIB_EXPORT_CLASS(rviz_plugin_tutorials::TeleopPanel, rviz_common::Panel)