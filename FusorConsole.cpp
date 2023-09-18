// Model of fusor
// Copyright(C) 2022 Ivan Volkov
//
// This program is free software : you can redistribute it and /or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.If not, see < https://www.gnu.org/licenses/>.


// FusorConsole.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "FusorConsole.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TheAppCode // _FILE_COPY_(_IN_FILE_NAME,_OUT_FILE_NAME)
// Единственный объект приложения

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: вставьте сюда код для приложения.
            _PrintLicence();
            // TheAppCode
            Nucleus Atom[2];
            Atom[0].clear();
            Atom[0].push_back(Nucleon::neutron);
            Atom[0].push_back(Nucleon::proton);
            // DefaultCharType Names[2][8] = {"neutron", "proton"};
            OutPutResult("\r\n%c_%c\r\n", Name(Atom[0][0]), Name(Atom[0][1]));
            Atom[1].clear();
            Atom[1].push_back(Nucleon::neutron);
            Atom[1].push_back(Nucleon::neutron);
            Atom[1].push_back(Nucleon::proton);
            OutPutResult("\r\n%c_%c_%c\r\n", Name(Atom[1][0]), Name(Atom[1][1]), Name(Atom[1][2]));
            // *****
            Atom[0].push_back(Atom[1][1]);
            Atom[0].push_back(Atom[1][2]);
            Atom[1].pop_back();
            Atom[1].pop_back();
            OutPutResult("\r\n%c_%c_%c_%c_\r\n%c\r\n", Name(Atom[0][0]), Name(Atom[0][1]), Name(Atom[0][2]), Name(Atom[0][3]), Name(Atom[1][0]));
            Print_F("Press any key\r\n");
            PressAnyKey;
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
