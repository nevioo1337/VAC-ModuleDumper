# VAC-ModuleDumper
Dumps VAC(Valve Anti-Cheat) modules that get streamed and mapped while playing a VAC protected game

![Screenshot 2023-05-07 175548](https://user-images.githubusercontent.com/102999825/236688489-adae4297-7a3a-4210-a667-2e77ae0160b4.png)

## LoadVACModule pseudocode
```
// #STR: "c:\\buildslave\\steam_rel_client_hotfix_win32\\build\\src\, "pModule->m_hModule == NULL", "c:\\buildslave\\steam_rel_client_hotfix_win32\\build\\src\, "pModule->m_pModule == NULL", "_runfunc@20"
char __thiscall LoadVACModule(char *this, _DWORD *VACModuleObj, char Flags)
{
  _DWORD *VACModuleCopy; // esi
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // eax
  char *v9; // edi
  char *v10; // ecx
  BYTE *v11; // edx
  HMODULE ModuleHandle; // eax
  FARPROC v13; // eax
  int v14; // eax
  bool v15; // zf
  int v16; // ecx
  int v17; // eax
  int v18[10]; // [esp+8h] [ebp-28h] BYREF

  VACModuleCopy = VACModuleObj;
  if ( VACModuleObj[3] )
    return 1;
  if ( VACModuleObj[6] && VACModuleObj[5] )
  {
    if ( VACModuleObj[2]
      && !(unsigned __int8)sub_100A0E20(
                             "c:\\buildslave\\steam_rel_client_hotfix_win32\\build\\src\\SteamServiceClient\\servicemodul"
                             "emanagerbase.cpp",
                             542,
                             (int)"pModule->m_pModule == NULL") )
    {
      __debugbreak();
    }
    if ( VACModuleCopy[1]
      && !(unsigned __int8)sub_100A0E20(
                             "c:\\buildslave\\steam_rel_client_hotfix_win32\\build\\src\\SteamServiceClient\\servicemodul"
                             "emanagerbase.cpp",
                             543,
                             (int)"pModule->m_hModule == NULL") )
    {
      __debugbreak();
    }
    if ( EncryptionStuff(VACModuleCopy[6], VACModuleCopy[5]) )
    {
      sub_10059350(this, (int)VACModuleCopy);
      VACModuleCopy[4] = 11;
      return 0;
    }
    if ( (Flags & 2) != 0 )
    {
      v6 = sub_1004E930((_DWORD *)VACModuleCopy[6], 0, 1);
      VACModuleCopy[2] = v6;
      if ( v6 )
      {
        v7 = sub_1004E8A0((int)v6, "_runfunc@20");
        VACModuleCopy[3] = v7;
        if ( !v7 )
          VACModuleCopy[4] = 25;
      }
      else
      {
        VACModuleCopy[4] = 22;
      }
    }
    else
    {
      VACModuleObj = 0;
      sub_100764F0(0, 0, 0);
      VACModuleCopy[4] = 0;
      if ( (unsigned __int8)sub_10083740((int)&VACModuleObj) )
      {
        sub_10077DF0((int)v18, VACModuleCopy[6], VACModuleCopy[5], VACModuleCopy[5], 0);
        v9 = (char *)&pszSubKey;
        v10 = (char *)&pszSubKey;
        if ( VACModuleObj )
          v10 = (char *)VACModuleObj;
        if ( (unsigned __int8)sub_100848B0(v10, (int)v18, v10, 0) )
        {
          v11 = (BYTE *)&pszSubKey;
          if ( VACModuleObj )
            v11 = (BYTE *)VACModuleObj;
          sub_100761A0(v11);
          if ( VACModuleObj )
            v9 = (char *)VACModuleObj;
          ModuleHandle = (HMODULE)sub_10084AA0(v9, 0);
          VACModuleCopy[1] = ModuleHandle;
          if ( ModuleHandle )
          {
            v13 = RunVACFunction(ModuleHandle, "_runfunc@20");
            VACModuleCopy[3] = v13;
            if ( !v13 )
              VACModuleCopy[4] = 23;
          }
          else
          {
            VACModuleCopy[4] = 22;
          }
        }
        else
        {
          VACModuleCopy[4] = 21;
        }
        sub_100753D0(v18);
        v14 = sub_100A9760();
        (*(void (__thiscall **)(int, _DWORD *, _DWORD))(*(_DWORD *)v14 + 28))(v14, VACModuleObj, 0);
      }
      else
      {
        VACModuleCopy[4] = 19;
        sub_100753D0(v18);
        v8 = sub_100A9760();
        (*(void (__thiscall **)(int, _DWORD *, _DWORD))(*(_DWORD *)v8 + 28))(v8, VACModuleObj, 0);
      }
    }
    if ( !VACModuleCopy[3] )
    {
      sub_10059350(this, (int)VACModuleCopy);
      return 0;
    }
    v15 = VACModuleCopy[6] == 0;
    v16 = dword_1041E0A4;
    VACModuleCopy[8] = dword_1041E0A0;
    VACModuleCopy[9] = v16;
    if ( !v15 )
    {
      v17 = sub_100A9760();
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v17 + 28))(v17, VACModuleCopy[6], 0);
      VACModuleCopy[6] = 0;
    }
    return 1;
  }
  VACModuleObj[4] = 12;
  return 0;
}
```
