// ccc Buildingset, new file	
/*
ccc Dec06:
� ������� �� ����������� ������ ������ � ���� �����, ���� �������� �� ������ ��������� ������, �� � ������������ ��� � �����.

��������� ����� ������� ��� �������� �������� ������������ ��� �������� ��������� ���������� ���������� �����. 
������ ����, ����� ������� ������ �� ����������� � ������������ ����� ������, � ����������� �������� �����.. 
������ ������ ����������� �������� ������� ��������� PotC. : 
��� �������� �������� �����  "x-dialog.c" ��������� ������ ������������� �������� ���� ���������� ������� "x-dialog.h"  �� �������� dialogs\english (��� �� ����� Russian, ���� �� ����������� ���� ����). 
��� ���������� ����� ������ ����.

������ � ����������� ����� ��� � ������� ����� � ����� ����� �� ���� ��������:
-������ ������� �����
-� ��� ������� ������ ����� � �������������� ��������
-���������� � �����, ������� ������ �� �������� ���, ������� ����� ������ � �������� ����.
��������� ����� �������� ����� ��� ����, ������ ��� �� ������ ���� ������������ ��� �����, ������� ����� ������ ���������� ���������.
��� ������ � ������������� �������� ���������� ������ "��� ���� ���������� �����".

� �������� ������� ������� ����������� � �������� ��� ����� �� � �������� ����� \dialogs, � � �������� \dialogs\English.
�������, ���� �� ������ ��������� ���� ������, �� ������ ������ ����������� "��� ���� ���������� �����" � �������� ��� ������ ����� � ��������� ��� ���������� �����..
���, ����������, ����� ������ ������ � �������, ��� ����� ��������� ��� �����. 
�� ������ ��� � ������ � ���������, ������� ������ �������� �������.
*/	
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			NextDiag.TempNode = "first time";
			dialog.text = "������, ������� " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + ", ��� ������������ ����� ���������� � ���� ����� ��������� �����������, ������ ���� ������� � �������� ������������ " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + ", ��� ����� ������ ����� ��������� ��� �������� �������. �����, �����-�� ��������� ���������� �� ����� � �������, �����-�� �������� ����������� ���� � ����������� �����.. � ����������� ������������� � ��������! ������ ������ - ����������� ������ ���� ����, ������������ ������ ���� �������� ������, �� ���� ��������� � �����������. ������ �����? �������� ������? ����� ��� ����� ��� ���, ��� �� �������� � ��������� ��������.";
			link.l1 = "��? ��.. � �� ������ ���� �� ����� �����.. ������ �� ������ ��� �������� � ���������?";
			link.l1.go = "help_2";
			link.l4 = "����, ��������������, ��� �� ���������� ��������� ��������? ��� � ���� ���� ������, ��� �� �� ��������� ��� ����, �?";
			link.l4.go = "help_3";
			link.l2 = "(����, ��� ��� '������� ��� ��������� �����'? ��, �����..) ����... ��� � ����, ��������� ����� ����� �������� � ��������, ����� �������� ����, ����������� ����������, ��� �������� ������������, ���� � ����, ��� ��� ����� ����� ����� ������� � �������, ������� ���� ����������� ������� �������� ���������. � ������� ����� ������� ����!";
			link.l2.go = "items";
			link.l3 = "��, ����������, �� �� ����� ������ ������� � ���� ��������?";
			link.l3.go = "items1";
		break;

		case "help_2":
			dialog.text = "����, ��� �� ���, ������� �� ���� ������� ������ ��� �����, ��� ��� ���������� �������, ����������� ������ � ������, �������, ��, �� ��� ��� ������� ����� � �����, ���� ��� ����� ����� ������� ����, ������� ����, ������ ����� �������, ������� ����� �����-��, ������� ������� ������ ���� ���� ����. ��� �� ������ ���� ��� �� ���������, ���, ��� ������ �� �������, ����� ������������� �� ������� ������. �� ������, ����� �� ��� � �����? ��� ������ ��� �����? ��� ������, ����� ��� ����������? ��� ������ � ���, ����� ��� ��������? �����, �������!";
			link.l1 = "�, �� ����, o ������ ���������, �� ����� �� ���������� ���� ��� ����, ����� ����� ����� ������! �� ��, ���� �� ��������� � ����������, - ��� ��, ��� ������ ��� ������ ��� ������. ���� ������� � ���������� ��� �� ���� ������, ��� � ��� ������. ";
			link.l1.go = "items";
		break;

		case "help_3":
			dialog.text = "�� ����, ��������, ����������� � ���� ������� �����! ��� ��� ������ ���������� ������ �������, ������ � �������. ���� �� ���� ������ ������ ����� �������� ������, � �� ������� �� ��������, ����� ��� �� ������� ������ �������. ���� �� ���� �����, ��������� ����������� ����� �������, ����� ������ ������ ������ � ����� ������� ������ �����, �� ��� �������� �������� ������������, � ������� ��� ��������� ������� ������� �������. �� ������ ����, ����� ������� ������ �������, ����� �� �������� �� �� ���, �� ��������� ��������� � ����� � ������. �� �� ������, ��� ��������� ��������� ��������, ������������ ������ ������ �������. �������������� ��������, ����������, � ����������� ���� ���� ����� ������ ��� �� ������, ��� � ����� ��� ������ �����. �� ������ �� ������ ���� ���� ���� ������ ������������, ���� ������ ��������, ��! � � ���� ����, ���� ���� ������!";
			link.l1 = "��� ��� �������� ���� �������, ����� ������ ���������, ����� ��� ������ ���� � ��������� ��������� ���� ������ ����. ��� �� ����������-������� � �������, ���� �� ��� �� ����!";
			link.l1.go = "items";
		break;

		case "items":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 100 ); }
			else { AddPartyExp(PChar, 100 ); }
			WaitDate("", 0, 0, 0, 2, 0);
			dialog.text = "��� �� ������, �����������! �� ���� ����������� ��� ������, �������� ������ ������� ������������ ������, �������� ����������� ��� ��������� ������ ���������� ����������! ��� �������� ��� �������� �����, ����������, � ����� ���� ��� ����� �������� ���� 100 ��������� ��������! (��������� ������ �������... � ������� ���� �����) ����, ������ ������ ����, ����� ��� ����� ��-��� ��������! ������ � ������ ����� ��������� ���� � ���, ��� �������� ��� ���� ���� ������� � ���������� �����?";
			link.l1 = "���.. ��, ����������! ��� ������, ��� ������ ���������, ��?";
			link.l1.go = "items1";
		break;

		case "items1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LaunchCharacterItemChange(NPChar);

			ChangeCharacterAddress(NPChar, "none", "");
			Logit("��������� �������� ��� ���� � ������, ������ ������� ����� ��������� ���...")
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterAddress(NPChar, "none", "");
			Logit("��������� �������� ��� ���� � ������, ������ ������� ����� ��������� ���...")
		break;
	}
}
