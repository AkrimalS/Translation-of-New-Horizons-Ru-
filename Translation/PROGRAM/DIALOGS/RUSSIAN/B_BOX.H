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
	ref lcn = &Locations[FindLocation(PChar.location)];

	string nr = NPChar.lastname;

	string buildingstr = NPChar.equip.blade;
	aref buildingref;
	Items_FindItem(buildingstr,&buildingref);

	string interiorstr = "simple furniture";
	if(CheckAttribute(Npchar,"equip.gun"))
	{
	interiorstr = NPChar.equip.gun;
	aref interiorref;
	Items_FindItem(interiorstr,&interiorref);
	}

	int planks = 0;
	int money = 0;
	int crew = 0;
	
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
			Dialog.snd = "voice\PADI\PADI001";

	
			Dialog.text =  "������� �������, ���������� ������� � �����. ������ ������������ � ����� ���� ������������ � ������� �������.";

			link.l1 = "��� ����� - ������ ����������� ������. ������! ����� ��� ��������. � �������� ����� � ��� �������.";
			link.l1.go = "dismantle";

			if(!CheckCharacterItem(NPChar,"pistolgrenade") && CheckCharacterItem(PChar,"pistolgrenade") )
			{
					link.l21 = "��� ��� ���������� ����� ��� �������. ������� � ��������� ������, ������������� � ������, ������ �������� ��������� ��� ������ ����������� �����. � ���� �� ���-������ ������ ����� ����������...";
					link.l21.go = "grenade";

			}
			Link.l4 = "��� ����� �������� ��� ����� � �����...";
			Link.l4.go = "exit";

			link.l9 = "��, �� ���, ����� �����������! ��� ������, ������� �� �������, ��� ��� ������ ����, ����� ������� ���� ����������� ������? ������ ����������� �������, ����� ������� ���� program\dialogs\" " + NPchar.dialog.filename + " ������������ ���� ����� �����. ����� �������� ����������� � ������������.";
			link.l9.go = "your_dialog"; //��� ��� ������, ������� �����������, ���� �� �������� ���������� ���� l9. ��� ����� ��� ����.
		
		break;
                
		case "your_dialog":
			Dialog.text = "������������ ��� ���������� ������� NPC." ;

			link.l1 = "����� ����� ������� ������ link.l1, ������� ��������� ������ ";
			link.l1.go = "exit";	// ������ l1 ��������� ������

			link.l2 = "����� ����� ������� ������ link.l2, ������� ����� � ������� ������ ";
			link.l2.go = "your_dialog2";	// l2 �������� � ������ your_dialog2
		break;	// ����� �������� "���_������"
                
		case "your_dialog2":
			Dialog.text = "������������ ��� ���������� ������� NPC." ;

			link.l1 = "����� ����� ������� ������ link.l1, ������� ��������� ������";
			link.l1.go = "exit";	// ������ l1 ��������� ������

			// ��� ��������� ������� ������, ������� ���� ��� ������, ��������, ������ ��� ����. ����� ������������ ��, ������� ����� ����� ����������� �//� ����� �����. �� ������ �������� ����� �� ���� ����������.

			// AddMoneyToCharacter(Pchar, 1000);

			// GiveItem2Character(Pchar, "Spyglass3");
			// GiveItem2Character(Pchar, "Jewelry5");
			// GiveItem2Character(Pchar, "Mineral3");
			// TakenItems(Pchar, "potion1", 3);

 			// AddCharacterGoods(pchar, GOOD_SANDAL, 10 );
			// AddCharacterGoods(pchar, GOOD_SILK, 10 );
			// AddCharacterGoods(pchar, GOOD_RUM, 20 );
			// AddCharacterGoods(pchar, GOOD_WHEAT, 20 );

			// AddPartyExp(PChar, 100 );


		break;	// ����� �������� "���_������2"

                
		case "grenade":
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "dismantle":
			DialogExit();
			planks += sti(buildingref.building.planks);
			crew += sti(buildingref.building.crew);

			if(CheckAttribute(Npchar,"equip.gun"))
			{
				planks += sti(interiorref.building.planks);
				crew += sti(interiorref.building.crew);
			}
			AddCharacterGoods(pchar, GOOD_PLANKS, planks);
			AddCharacterCrew(pchar, crew);   // ccc mar06
			Lai_KillCharacter(npchar);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
