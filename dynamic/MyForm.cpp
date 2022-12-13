#include "MyForm.h"
#include <Windows.h>
#include <vector>
#include <fstream>
using namespace dynamic;
using namespace std;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

double pi = 3.14;

System::Void dynamic::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();


	double fi, fidt;
	double t = 0.0, dt = 0.001;
	double x0=pi/8, y0=0.0;
	double omega = 1.0;
	double A = pi / 8;
	while (t < 7.0) {
		fi = x0 * cos(omega * t) + y0 / omega * sin(omega * t);
		fidt = -x0 * omega * sin(omega * t) + y0 * cos(omega * t);
		t += dt;
		this->chart1->Series[0]->Points->AddXY(t, fi);
		this->chart1->Series[1]->Points->AddXY(t, fidt);

	}
	return System::Void();
}

System::Void dynamic::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();


	double fi, fidt;
	double t = 0.0, dt = 0.001;
	double x0 = pi / 8, y0 = 0.0;
	double omega0 = 1.0, sigma=0.05;
	double omega = sqrt(omega0 * omega0 - sigma * sigma);
	double A = pi / 8;
	while (t < 20.0) {
		fi = exp(-sigma*t)*(x0*cos(omega*t)+(y0+sigma*x0)/omega*sin(omega*t));
		fidt = exp(-sigma * t) * (y0 * cos(omega * t) - ((omega*omega+sigma*sigma)*x0+sigma*y0) / omega * sin(omega * t));
		t += dt;
		this->chart1->Series[0]->Points->AddXY(t, fi);
		this->chart1->Series[1]->Points->AddXY(t, fidt);

	}

	return System::Void();
}

System::Void dynamic::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();


	double fi, fidt;
	double t = 0.0, dt = 0.001;
	double x0 = pi / 8, y0 = 0.0;
	double omega = 1.0;
	double A = pi / 8;
	while (t < 7.0) {
		fi = x0 * cos(omega * t) + y0 / omega * sin(omega * t);
		fidt = -x0 * omega * sin(omega * t) + y0 * cos(omega * t);
		t += dt;
		this->chart1->Series[0]->Points->AddXY(fi, fidt);

	}
	return System::Void();
}

System::Void dynamic::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();


	double fi, fidt;
	double t = 0.0, dt = 0.001;
	double x0 = pi / 8, y0 = 0.0;
	double omega0 = 1.0, sigma = 0.05;
	double omega = sqrt(omega0 * omega0 - sigma * sigma);
	double A = pi / 8;
	while (t < 50.0) {
		fi = exp(-sigma * t) * (x0 * cos(omega * t) + (y0 + sigma * x0) / omega * sin(omega * t));
		fidt = exp(-sigma * t) * (y0 * cos(omega * t) - ((omega * omega + sigma * sigma) * x0 + sigma * y0) / omega * sin(omega * t));
		t += dt;
		this->chart1->Series[0]->Points->AddXY(fi, fidt);

	}
	return System::Void();
}
