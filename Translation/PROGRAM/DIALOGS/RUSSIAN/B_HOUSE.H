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
#include "DIALOGS\English\B_resident_text.h"

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
	PChar.storekeeper.Idx = -1;//MAXIMUS
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

	int grgbonus = 0;

	int iDYear = sti(lcn.building.(nr).taxyear);
	int iDMonth = sti(lcn.building.(nr).taxMonth);
	int iDDay = sti(lcn.building.(nr).taxDay);
	int taxdays = GetPastTime("day", iDYear, iDMonth, iDDay, 1, GetDataYear(), GetDataMonth(), GetDataDay(), 1);
	int tax = 0;

	string adress;
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " my landlord ";}else{adress = " " + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " ";}

	PlayStereoSound("ambient\town\cough.wav");
	PlayStereoSound("ambient\shop\sigh2.wav");

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

			if(rand(100)<15) // ���� ��������� �����, ��������� ��������� ����� ��� �������� ���������� ����
			{
        		ChangeCharacterReputation(Pchar, -2);  // ���������: ������ ���������. ����� ��������������, ���� ������� ���
        		PlayStereoSound("voice\ENGLISH\Eng_m_a_070.wav");	
				Dialog.text =  LinkRandPhrase("����� ����, ��� �� ������! �� ������ �������� ��� �� ���� ������..", "��, ���� ������� ��� � ����� ������������� ������: �� ���-��� ������������ ���������. ������ ���!", "����� ����������, � ������, �� �������� ��������� � ������ ������ " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + " ����� ��, ����� �� ������� �� ����� ������...");
				link.l1 = "��, ���������! ����, ����, �� ��� �������� �� ������... � ������ ����� ���, ��� ����� ����������.";
				if(rand(100)>60) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "�, �� �����, �� �� � ��������� �������� ����, �� ��� ��? � ���� ���� ������ ����, � � �� ����, ����� ���� ���������� ��������� � �����!";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  LinkRandPhrase("��, ��� ������� ������� �������� ���� " + buildingstr + ". ��� � ���� ������� ��� ���," + adress + "?" , "����� ���������� � ���.. ���.. ��� " + buildingstr + " , " + adress + ", ������ ���� �������?" , "����� ����������, " + adress + ". ��� ������� ��� � �����.. ���.. ������ " + buildingstr + "?");
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = "�, � �������� ���� ������! ���������, ������� ����������, ���������� ������ ���� ���... �����, � ���� ��������!";
					Link.l1.go = "infected";
				}
				Link.l2 = B_TEXT[8];
				Link.l2.go = "heal";
				
				if(interiorstr=="marketstall")
				{
        	link.l3 = "������� ������� �� �������� ��������� �������. � �� ����� ��������� �� ���� ������.";
				  link.l3.go = "shop";
        }

				Link.l4 = LinkRandPhrase(B_TEXT[9], B_TEXT[10], B_TEXT[11]);
				Link.l4.go = "chat";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // ���� �� ��������� �������������
				{

	   			if(taxdays>0)
	   			{
  					link.l5 = "��� �� �������, ���� ����� ���� ������������, �? ��� ��� ��� �������� �� ��� ����, � � ����� �� �������� ��������� ������ �� ����� ����������, � ������, ������� � ��������� ���, ���� �� �� �����. ����, � ����� ��� ����, ����� �������� ������. ������� �� ���������� �� " + taxdays + " ���� � ������� ���������� �������?";
  					if(rand(100)*sti(pchar.reputation)/50 > 20)   // ����������� ������ �� ��������, ��������� ��������� ����� ��� �������� ���������� �������
            {Link.l5.go = "tax";}
  					else{Link.l5.go = "taxevasion";}
					}

        	link.l6 = "��, ���������, ���� ��� �������� " + buildingstr + " ����� ���� ��������.";
				  link.l6.go = "interior";

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l7 = "����������, �� ���� �������� ����� ��������, ����������, ������� ������������ ��������, ������� � ���������������. ����� ����, ��� �������� ����, � � ���� ������ ��� ����� �����-�� ��������� ��������. ���, ������ ��� �������...";
					link.l7.go = "grenade";
					}

					link.l8 = "��� ������ �� ����� ��� �����������. ��������� ��, ��������� ����� � ��� ���� � �������� ������� � ������� ������������.";
					link.l8.go = "dismantle";

				}
				else   // ���� �� �� ��������� �������������
				{
					link.l9 = "������ �������� ����... ";
					link.l9.go = "exit";
				}

				Link.l10 = B_TEXT[12];
				Link.l10.go = "exit";

				link.l11 = "��, ������ �� ������ ����� ��� ����������? " + LinkRandPhrase("�� ���������� �����...", "�����, ���������� �������...", "� ������ ������� ������� ���������� �� ���� �����������, �� ���� �������?");
				link.l11.go = "motion";

				link.l12 = "���, �������� ����, � �� ���� ���� ��������, �� ��� '������' �������� ������� ������� ��� ����...";
				link.l12.go = "odd";

				link.l13 = "��, �� ���, ����� �����������! ��� ������, ������� �� �������, ��� ��� ������ ����, ����� ������� ���� ����������� ������? ������ ����������� �������, ����� ������� ���� program\dialogs\" " + NPchar.dialog.filename + " ������������ ���� ����� �����. ����� �������� ����������� � ������������.";
				link.l13.go = "your_dialog"; //��� ��� ������, ������� �����������, ���� �� ��������� ���������� ����� l13. ��� ����� �����.
			}
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

// ���� ������� ������ ��� �����������                
		case "grenade":
			Dialog.text = "...� ���� �����-������ ����� ��������� ����� � ���... �-�-�.. ���� ��������, � ������� �� � ��� � ����." ;
			link.l1 = "��� ��� ���! ������� ����� ����� ������ ���������. �� ���� ��������� � ����, ���� �� ���������..";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// �������� ��������
		case "interior":
			Dialog.text = "�, ��, �� ����� �� �������� "+interiorstr+" ������� � ��������� ����� � ��� ����, ���� �� ������ ���� ����� �������� " + buildingstr + " ����� �������. �� ������ ������ ���� ��� "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" �����, "+ pchar.money +" ������ � "+ Pchar.Ship.crew.quantity +" �����. ��� �� ������� �� ���� �����?";
			Link.l1 = "��, � �� �����, ��� � ������ ���������� ���� ��� ������.";
			Link.l1.go = "exit";
			Link.l8 = "�������� �������� (���������� ��� � �������� �����, ������ ������; 5 �����, 5000 ������, 3 ��������)";
			Link.l8.go = "marketstall";
			Link.l5 = "��������� ������ (�������� ���� ��������� ������� ��� � �����; 5 �����, 1000 ������, 1 �������)";
			Link.l5.go = "luxurious furniture";
		break;

		case "marketstall":
			npchar.interior = "marketstall";
			Dialog.text = "���� " + npchar.interior + " ?";
			Link.l2 = "�����. ��� �������� ������� ��� ����������� �������, � � ������, ��� �� ��������� ������ �� ����� ���������� ������. ��������!";
			Link.l2.go = "erect";
		break;

		case "luxurious furniture":
			npchar.interior = "luxurious furniture";
			Dialog.text = "���� " + npchar.interior + " ?";
			Link.l2 = "�����. ��� �������� ������� ��� ����������� �������, � � ������, ��� �� ��������� ������ �� ����� ���������� ������. ��������!";
			Link.l2.go = "erect";
		break;

		case "erect":
			aref interiornewref;
			Items_FindItem(npchar.interior,&interiornewref);
			planks = sti(interiornewref.building.planks);
			money = sti(interiornewref.building.money);
			crew = sti(interiornewref.building.crew);

			if(money > sti(pchar.money) || crew > sti(Pchar.Ship.crew.quantity) || planks > GetSquadronGoods(pchar,GOOD_PLANKS) )
			{
				Dialog.text = "��, ���, ���� " + npchar.interior + " ������� " + planks + " �����, " + money + " ������ � "+crew+" �����. ��, ��� � ��� ������, � ��� ���� ������ "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" �����, "+pchar.money+" ������ � "+Pchar.Ship.crew.quantity+" �����...";
				Link.l3 = "���.. ���������.. ������.. ��� �, ������, ���� �������� ���� � ���� ����� ��� ����..";
				Link.l3.go = "exit";
			}
			else
			{
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;

				// ����� ������������ �������
				RemoveCharacterGoods(pchar, GOOD_PLANKS, planks-1 );
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar, -money);
				Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -crew;

				// ������� ������ ���������
				lcn.building.(nr).interior = npchar.interior;
			}
		break;


// ��������� �����
		case "attack1":
			Dialog.text = "������� ������! ��� ����... ����� ��������� ��������! ��, ���� �� � ��� ���� �������� ���� ���������, ����������, ��� � �����...";
			link.l1 = RandSwear() + "��� ��� ���������� ������������ �������! ������������ ������ �� ����. ������, ��� �������� ��������� ��� ���.";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "������� ������! ��� ����... ��������� ������� ������� � ��� ���� ��������������� �������������! �������� �����, ������� � �������... ��, ���� �� � ��� ���� �������� ���� ���������, ����������, ��� � �����...";
			link.l1 = RandSwear() + "��� ��� ���������� ������������ �������! ������������ ������ �� ����. ������, ��� �������� ��������� ��� ���.";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: ����� ��� �� ������� �� �������� �������
			ChangeCharacterReputation(Pchar, 4);  // �������: ���������. �������� �� ������ �����
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // �������: ����. �������� ��������� ����� �� ���� ����������
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: ����� ��� �� ������� �� �������� �������
			ChangeCharacterReputation(Pchar, 4);  // �������: ���������. �������� �� ������ �����
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // �������: ����. �������� ��������� ����� �� ���� ����������
			Ambush("Soldier_Spa2",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// ������ � ������ ������� � ��������������
		case "tax":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// �������������� �������, �� ������ �������� ����� ����� ';' �� ��� ����
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// ������� ��������� �� �����, ������� ������, ����� ��������� ���
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = RandSwear() + "���? " + taxdays + " ���� ��� ������? ������, ��� ������� ��������� " + npchar.tax + " ������," + adress ;
			link.l1 = LinkRandPhrase("�������, �������� ����������. ��� �, ���� ������� ������������� � ����, �� � ������ ���� ������. �� ������� *������������* ","��� ���� ���� ����� ����������? ���� � ����������� ���� ���� �����������: �������, ������, ����, �������.. ��� ��� ����� �����������, ���� ��� ���� ������ �������� � ����.. ���.. � ������������ �����.","� ������ ���... ���... ���������� �� ����. ����� ����, �� �� ��� ����� ��������� �� �� ������� � �������� ����, ��� ��� � ����� �� ���������, ���� � ���� ������� ���� ������ � ������������� ����������.");
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("�������� ������. � ������� ���� ��������. ����������� �� � ����, ����� ��������� ���� ���������. (� ��� ����..)","����, �� ����� ��������, ��? � ������� �� ��� � ������� ���� �������� �� ���� ����������� ����.(� �������, ��� �� ������ �������� ��� ��������..)","����������, � ������� ��� ��������, ����� �� ����� �������� ���� ������� ����� � ������. � ����, ����� ��� �������� ���� ��������� � ���������� ������. (� ����������� � ����������..)");
			link.l2.go = "taxhalf";
			link.l3 = "������ " + npchar.tax + "? ��� ��� ��� ������������? �� ����� �� �� ���������� ����, ����������.";
			link.l3.go = "economy";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // ���������: ������� ���������. �������� �� ������ �����

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// �������������� ���������� ��������, �� ������ �������� ����� ����� ";" �� ������ �����
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// ������� ��������� �� �����, ������� ������, ����� ��������� ���
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = RandSwear() + LinkRandPhrase("��, ����� ��������, ������, �� � ��������� ����� � ��� ���� ������� �������: ������ ��������� �������� ��� ���� �� ������, � �� �� ����� ���������� ������� �����...", "��� ������ ����, �������, �� � ���� ������� �� �������� �� ����� ������: ��������� ������� ����� �����-�� ��� ����� ���, ��� � �������� ��� ����. �� ������������� ������ ������� ������ ��� ������������ ������ ���������...", "��� ��������� ��� ��������, ���� ���������, �� �� ���� �� �������� ����� � ����� ��������: ������ �����, ������ ������ � ����� ������ ���������� �������� ��������, ��� �� � ���� ����� ��� ����� �����, ����� ������� ��, � ���, � ���� �������, ��������, ��� ��� �� �� ��� ����������. ���� �� ��� ������ ��������� �������� ����� � ����� ������ �� ���� ���������������, �� ������ ��������� ��������...") ;
			link.l1 = LinkRandPhrase("��� �, ���� ���� ������������� ��� ������, � �� ����� ��������� �������� ��� ������: � ����� ��� ���� ������, �� ������ �� ���� ���. ������ ��� � �� ���� ��������� ���� ������� ����� ��������� ��������, � ���� ������� ���� ������� ��� ���������, ������ ���� ��� ������� ���� ��� ������� �����.", "������, ������� ��������� ���� ������. �� � ��������� ��� � ������ �� ���� ������� ������� ����������... � ����� ������, ��������������, ��� ��� ���� ������ ���� �� ���������� ����� �������, � ������ ����� ���������, ���� �� �������� �������� ����� ������.", "��, ��� �������� ������ ������� ������, ������� �� ������ �������, �� ��� ��? �� ���� ��� � ���� ��� � ������, �� � ������, ��� �� ����������� ������, ��� ������ � ��� ��� ���������. ���� ��� ������� ����� �������, ��� � ������� ����� � ����, �����������.") + "";
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("�������� ��� �����, � ������� ����� ������ ��� ������ ����������, ����� ������ � ��� ������. �� ���������, ����� � ������.", "�����, �� �������������! ��� �� ����� ����... � ������ ������ ��, ��� ��� �����������, �� ������, �� � �� ������.", "��������, ��, ������� �������! �� ���� ���������� ��, ��� ��� �������� �� ���������, ���� ������� ����� ������ ����� � ��������.");
			switch(Rand(5))   // ���� ��� ������������� �� ������ ������� ���������, ��������� ���������� ��� �������� ���������� ��������� � �����������
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxfull"; break;
			}
		break;

		case "taxhalf":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax)/2 );
			ChangeCharacterReputation(Pchar, 1);  // �������: ���������. �������� �� ������ �����
			Dialog.text = "��� ����� ����� � ����� �������, ���. � ���� ��������, ����� �� ������ � ���������� ������, ������ ���� � ���� �������!";
			link.l1 = "��, �� ����������, � �� ��� �������� � ����� ���������. ������, � �������� ���� ���� ������� �������. ������ �� ���� �� ����� � ����� ������, �� ���������� � ����������, ����� ���������... ����������!";
			link.l1.go = "exit";
		break;

		case "taxfull":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // ���������: ������� ���������. �������� �� ������ �����
			Dialog.text =  RandSwear() + LinkRandPhrase("�� ���, ������ ���� ������� ������. �� �� ���������, ���� �� ����� ���������� ��� �����������, ������ ��� �� ��������...", "����� � ���� ��� ������� ������, ����� ��� �������� ��� ���� ������ � ����������. ��������, ��� �, ��������, ������� �� ��������� �����... � ������ ������...", "�����, ������, ������ ��� ������, ������� � ������� ��� ������� ������.") ;
			link.l1 = "��, ���������, ���� �� ������� ����� ��������� ��� ���������, ��������� �� ���� " + npchar.tax + " ������� ";
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // ���������: ������� ���������. �������� �� ������ �����
			Ambush("outlaws", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + "��, ���, ������ ���� �������� ����� �� �����, ��, ����������������� ������������. �� ���� ������, ��� ��������������� ��������� ������������� ��� ��������� ���� ��������� ����� �������� ���������� �� ���! ������� ���� ��������, �������������! ����� ���������� ���!";
			link.l1 = LinkRandPhrase("�� ����� ���� ��������, �� ���� �� ���������, ��� ��� �����, ��� �� �������.","���? ����������� ������������ ������� ��� ��� ����������? ����� ���� ������������� �� ����������, ��� '������������' ���������� ���������� ��������� ��? ��� �, ������� �� ������ ���� ������ � ��������������� ����..","���! ����������� ������������ �������! ����� � ���� ����������� ��������!");
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			Dialog.text =  RandSwear() + LinkRandPhrase("��� �, ���� �� �������� � ���� ��� ���������, � ������ � ���� ����! � ����� �� ����� ������! ������ ������, �� ������ ��? ��� ����� - �� ��� ����, ��� ������ �����...","�� - ��� ��������! �� ��� � ������ ����? � ���� ��������! ... ���! � �� ����! � ����� ���� ������,� �������, � �� �� ������! ��� ��� ��������� �����?","�� �������� ��� �����, ��, ������! ���, ��� � ���� ��������, ��� ���� ������� ����... ���������� ������� ���, ���������� ���� �����, ��� ������ �����... ���� ����� � ���... �� ������� ����, ��������? ������ �����, ������� �� ��������! ��-��, ���� ��� ����� �� ������ � �����...");
			link.l1 = LinkRandPhrase("��, �� �����, ������ �� ������������� ��������������..","��, ��� �� �������? ���������, �� ������ ����� �������� ����������� ������ �� ����������� �������..","�����, ���� ����, ���� ������. ����� �������, ��� ��, ����� ��������..");
			link.l1.go = "taxsuicide2";
		break;

		case "taxsuicide2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Explosion (NPchar, 30);
			Lai_KillCharacter(NPchar);
		break;


// �������� ����� ������
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

// ���������� � ��������
		case "odd":
			Dialog.text = "��, �� ��� ��� ��������... ��� ���������� ������� ��� '����������' ����� ������ ������ �����! ���� ����� ��, ��� ����� ��������� ������������, ��� ���� ����� ��������� ����� ������ ���. �������� ���������, ���� � ���� ����������� �������! �� ���� ������� ������ ����������, ���������������� ���, �������� ������� ������. ���� �������-����������� �� ����� ���� ������ �� ����� � ������� �����, �� ������ ����� ��������� �������� � ���� ���� � ��������� �� � ����� ����������� ������." ;
			link.l1 = "��, �������� ���� ���! ����� �� ����� ����� �������� ���, ��� ������ �������� ����? �� �� ��������� ����� �� �����? �, �� ����� �������, ���� ������������ ����������������������� � ������������� ���� ����� ������ ������ ����, ����� ������� ���� ����� �� ��������.";
			link.l1.go = "exit";
			link.l2 = "������ ����, ����� ���������� �� ������, �� ������ ��������� ���� ������� ��������� � ������ �������� ��������������. ������ ������ ������� �����? � ���-��� ���� � �������������, ����� ����, � ����� ������?";
			link.l2.go = "odd2";
			link.l3 = "�� ��������� �������� �� ������� ���, ��� ��� �� ��������, ��� ��� ������������� �����: ����� ������� � �������. � ������� ��������� � �������, ���������.";
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = "����� ������ ����� ������� � ��������������. ��������� �� ���� ������� ������, ����������, ��������� � �������������. �������� �������� � ���, ��� ��� ������ ������ �� �������� ������ ������ �������, � �������� ����������, �������������� � ������������ ����������, ����� ��� �. ������� ���� ��� ������ �������������� -������� �� ��������� ���������� ��������� ������ �����- �� ���������������� �� ��� �����������. ��� ��� �����, ��� ��� ���� ������ ������������ ���������. ��� ������ ����������, � ������� ����������� ������������ ��������. ���� �� ������ ������� �����, ����������� ��� �� ������ �������� PotC �� ������ "+PA_INET;
			link.l1 = "����, � ������� �� ����...";
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = "�� ����� ���������� �� ���. �� ������ ��������� ��� ��������������, ������ �������������� ��������� ����. ��������, ��� ��� �� ������ ����� ��������� ��� ������� ��� (��-��): �������� ���� 'pirates of the caribbean\program\dialogs\ " + NPchar.dialog.filename + " � ������� ���������� ���������, ������ ��� �������. ����������� ������� ������ ��� ������ ��������� ����� 'reward'(�������). ��� �������� ��� � ����� ��� ���������� �������, �������� ����: ' npchar.tax = taxdays * 10;	// �������������� �������� ������... '. �������� '10' �� '5' ��� �������� ���� ��������. (�� �����, ��� � �������� ���, ��� �� ��������� ;) ). ����� ��� �� �� ������ ��������� ������ ����, �������� ����� �������� ���� 'chance'(����) ��� �������, ��� 'punishment'(���������) �������� ������ ���������. ����������� �� '//' ��������� ���, ��� ������ ���������� ���. ����� ��������� ������� ��������� �� ����� ������� ��� ������� � ������������ '// reputationinfluence (������� �� ���������)' � ������� ���. ���� ��� ����� �������������� ����������, �������� �� ������ �������� PotC �� ������ "+PA_INET;
			link.l1 = "��, ������� �� ���������. ������, ������� �� ��� �� � ������,��? ������ ��������� ������� �������� � ����������. �� ���� � ���� ������ � ��� ����, �� ����� � ����� ������� �� ���������.";
			link.l1.go = "exit";
		break;

		case "economy":
			Dialog.text = "������, ��� ��������� ���� �� ���������-������������� �������� ������ ��������: ������ ���� ���� ��������� � ���������� �������� � ����� ��������, ����������� ������������ ������ ��� ����������� ������. ������� ��� ��������� � ������, �� ������ ������� �� ������ ���������: ��������� ���� �������� ����� ����������, ��������� � ���� ���� ��������� � ������ �� �������, � ���� �� ���������� � ����� ����� �������� � �����������, ��� ������ �� ��������, ��� � ������� ����������� ������ ��� ������ ��� ������. � ��������� ������ ��� �������������, ����������� ��, ��� ������ ���� �����, ��� ���� ��������. ������� ����������� �������� ���� ���������: ��� ���� ���� ���������, ��� ���� ��� �����. � ��������: ��� ����� �� ������ ���� � ����� ��������, ��� ���� ���� ���������. ������� �� ������ ��������� �������������� ���� ����������� ����������� � ������� � ������� � ������������ ������������ ������ ��������. ���� �����, ����� ������, � �����������, ����� ������." ;
			link.l1 = "� �� ��������� ��� ���������������? ��-�����, ��� ������ ������ �� ������������� ����� ����. ���, ������, �������� ���������. ��� ���� ��� ����� ����������? ���� � ����������� ���� ���� �����������: �������, ������, ����, �������... ��� ��� ����� �����������... ���� ��� ���� ������ �������� � ����... �-�... ������������ �����.. ��� ��, ��� � ������� ���������������, �������� ����� � ������������� ������ ����� ����� ������!";
			link.l1.go = "taxfull";
			link.l2 = "� �������... ��������, � ������� ���� �������� ����� ����������, ����� �� ��� �������� ���� �������� � ������� �������. � ����, ����� ��� �������� ���� ��������� � ���������� ������. (����������� � ����������..)";
			link.l2.go = "taxhalf";
			link.l3 = "��� ��� �� ��������. � �� ����������� ���� ��������� �������� �� ���������� � ���, ��� ��������� ���� ��� �� ������ �����. ��� ��� ������� � ������� ������ �� �������� ����� ����� ����.";
			link.l3.go = "tweaking";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("��, � ��� ������� �� ������ �����������, ��� �� ���� ������������.", "�����, � ���� ���� �������, � ���� ��� ����� �����, � � �� ������� ���� ������ ���� ������������ ������.", "�� �� ��������, � ������ ������������ ���� ���. �� ������, ���� � �������� ���� �� ��������...");
			link.l1 = "������, � �������... �� ��������.";
			link.l1.go = "exit";
		break;

// enc_resident stuff: ���������, ���������� ������� � �. �. 
		case "chat":
			dialog.text = B_TEXT[17];
			Link.l4 = B_TEXT[12];
			Link.l4.go = "exit";
			Link.l1 = B_TEXT[18];
			Link.l1.go = "chat2";
		break;

		case "chat2":
			dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );

			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				Link.l1 = B_TEXT[22];
				Link.l1.go = "hall_day_wait";
			}
			else
			{
				Link.l1 = B_TEXT[23];
				Link.l1.go = "hall_night_wait";
			}
		break;

		case "heal":
			Dialog.text = B_TEXT[20];
			Link.l1 = B_TEXT[21];
			if (rand(100) + makeint(pchar.skill.Sneak) >= 35 || interiorstr=="luxurious furniture") {Link.l1.go = "exit recovered";}
			else {Link.l1.go = "exit infected";}
			Link.l3 = B_TEXT[24];
			Link.l3.go = "exit";
		break;

		case "infected":
			Dialog.text = LinkRandPhrase(B_TEXT[25], B_TEXT[26], B_TEXT[27]); 
			int winlink = rand(100) 
			if (winlink >= 50) 
			{
				Link.l1 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l1.go = "exit recovered"
			}
			Link.l2 = LinkRandPhrase(B_TEXT[41], B_TEXT[42], B_TEXT[43]);
			Link.l2.go = "exit infected";
			Link.l3 = LinkRandPhrase(B_TEXT[44], B_TEXT[45], B_TEXT[46]);
			Link.l3.go = "exit infected";
			if (winlink < 50) 
			{
				Link.l4 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l4.go = "exit recovered"
			}
			Link.l5 = B_TEXT[47];
			Link.l5.go = "exit";
		break;


		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
			PlaySound("VOICE\ENGLISH\Eng_m_a_013.wav");
			Log_SetStringToLog("�� �������� ������ � ������� �������.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\ENGLISH\Eng_m_a_014.wav");
			Log_SetStringToLog("�� �������� ������ � ������� �������.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "exit recovered":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit recovered2";
		break;

		case "exit recovered2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.poison = 0;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) + 1;
			LAi_SetCurHPMax(pchar);
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			RecalculateJumpTable();
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			Log_SetStringToLog("����� 24 ���� �� ����� � �����, ���� �������, ��� ������.");
			Log_SetStringToLog("+ 1 max HP");
			Log_SetStringToLog("�� ������ ������ � ������� ���.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Defence", 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
		break;

		case "exit infected":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit infected2";
		break;

		case "exit infected2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK ����� �������, ���� �� ����
			TavernWaitDate("wait_day"); // NK ����� �������, ���������� ���������
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			grgbonus = 200+Rand(200)
			PlaySound("OBJECTS\DUEL\man_hit6.wav");
			Log_SetStringToLog("�� ������������ � ��������� ���������.");
			Log_SetStringToLog("���� ���� �����, ��� �����!");
		break;

// ��������
		case "shop":
		  int quality = makeint(rand(8));
			NPChar.itemtrade.quality = quality;
			NPChar.itemtrade.tradetype = IT_TYPE_STALL;
			GiveItemToTrader(npchar);

			string qstr = "so so";
			if(quality>2)qstr = "quite good";
			if(quality>5)qstr = "booming";

			Dialog.Text = "��� �, �������� ��� "+ qstr +" �����. ������������ ������, ������� �� �� �������� - ��� ������ ������ � ����. ������� ��������� ���������� ������� ����� ���������, ��� �� �� ����� �������� �������, ������ ��. ����, ��� ��� �����, ���� ��� ������ ����?";
			Link.l1 = "� ���� ������� ����, ������� ������";
			Link.l1.go = "trade";
			Link.l2 = "���� ��������� ���� �����";
			Link.l2.go = "items";
		break;

		case "trade":
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(OXBAY_STORE);
		break;

		case "items":

			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

// ����� �� ����������� ����
		case "moraledrop":
			ChangeCharacterReputation(Pchar, 3);  // �������: ���������. �������� �� ������ �����

		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // ���������: ������ ��� �������. �������� �� ������ �����
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
