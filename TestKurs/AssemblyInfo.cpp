#include "stdafx.h"

using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;

//
// ����� �������� �� ���� ������ ��������������� ��������� �������
// ���������. �������������� �������� ���� ���������, ����� ��������
// ����� �������� �� ���� ������.
//
[assembly:AssemblyTitleAttribute("TestKurs")];
[assembly:AssemblyDescriptionAttribute("")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("")];
[assembly:AssemblyProductAttribute("TestKurs")];
[assembly:AssemblyCopyrightAttribute("Copyright (c)  2017")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];

//
// �������� � ������ ������ ������� �� ��������� ������� ��������:
//
//      �������� ����� ������
//      �������������� ����� ������
//   ����� ������
//      ��������
//
// ����� ������ ��� �������� ��� ������� ������ ������ � �������� �� ���������
// ��������� "*", ��� �������� ����:

[assembly:AssemblyVersionAttribute("1.0.*")];
[assembly:ComVisible(false)];

