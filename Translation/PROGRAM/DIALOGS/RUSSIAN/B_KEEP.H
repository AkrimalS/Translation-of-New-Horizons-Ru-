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

	string interiorstr = "";
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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " Commander, Sir, ";}else{adress = "";}

	PlayStereoSound("ambient\jail\chains.wav");
	PlayStereoSound("ambient\cave\drop5.wav");
	
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

			if(rand(100)<10) //  ���� ��� ��������� �����, ��������� ��������� ����� ��� �������� ���������� ����
			{
				PlayStereoSound("voice\Eng_m_a_070.wav");	
				ChangeCharacterReputation(Pchar, -2);  // ���������: ������ ���������. ����� ��������������, ���� ������� ���	
				Dialog.text = adress + LinkRandPhrase(" ���������� ��������� ����. ������������� � �������.", " �������� ���������� � ����� �������! ������������!", "�������������� ������������ �� ������ ���������, �������� � ������!");

				link.l1 = "��������� �����, ������, ������ ��.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "������ ���� � ����� � ����, ��� ���� ������! � ����� ������ ������ ��� ����� � ���� � ����� : � �������� ��������� ����.. ���.. ��������. � ���� ��� ����� ��� �������: � ������ ��������� ������� � ���� ���������� ����� ���, ����� ������-������ � ���������� ��������� ������ ��������� � ����� �����������.";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  "����� " + buildingstr + " ������������� � ����� � ��� ," + adress + " � ���� ������� ��� ��������.";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = "�� ������������ �� ���� �������. ��������� ��� �������� " + buildingstr + ", ��������� ����� � ��� ���� � ������� � �������� ���� ������� ������ ��� ���������� ����������� ������������.";
					link.l1.go = "dismantle";

					link.l21 = "��� ����� ���������� ����� ��� �������� ��������� ���� �������� � ����������, � ��� ������ �������� �������� ����� ���������� ������. ������ �������� ����� ���-��� ��� ����?";
					link.l21.go = "items";
					link.l22 = "� �� ����� ������������ ����� ���� � ����� ����� � ���� �������� ��������.";
					link.l22.go = "items";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l23 = "���������, ����� �� ����� ��������� ����� ������.";	// ccc feb06
					link.l23.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l24 = "������� ���������, � ���� ���� ��� ���� ������ �������: ���, ������ ��� �������, � ��������� �� ���� ���� ��������� � ������� ������� ��� �������...";
					link.l24.go = "grenade";
					}
				}
				else
				{
					link.l1 = "������ �������� ����... ";
					link.l1.go = "exit";
				}

				Link.l4 = "����� ������, ������� ���������, �����������.";
				Link.l4.go = "exit";

				// ccc feb06 link.l6 = "���, ���� ������, ������������� ���� �������� ��������? �� ���� ������� ����� � ����, ����� �� ��������� ������� � �����-������ ���� ��� �������..";
				// ccc feb06 link.l6.go = "odd";

				link.l5 = "��, ������ �� ������ ����� ��� ����������? " + LinkRandPhrase("�� ��������� �����...", "�����, ���������� �������... ��������!", "� ������ ������� ������� ���������� �� ���� ������� ����������, �� ���� �������?");
				link.l5.go = "motion";

				link.l9 = "��, �� ���, ����� �����������! ��� ������, ������� �� �������, ��� ��� ������ ����, ����� ������� ���� ����������� ������? ������ ����������� �������, ����� ������� ���� program\dialogs\ " + NPchar.dialog.filename + " ������������ ���� ����� �����. ����� �������� ����������� � ������������.";
				link.l9.go = "your_dialog"; //��� ��� ������, ������� �����������, ���� �� ��������� ���������� ����� l13. ��� ����� �����.
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
			Dialog.text = "...� ���� �����-������ ����� ��������� ����� � ���... �-�-�.. ���� ��������, � ������� �� � ��� � ����!" ;
			link.l1 = "��� ��� ���, �����! � ����� �������� ����� �� ����� ������� ��������. (..���� �� ��������� ��� �����..)";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// ������ ����� ������ ��� �����������               
		case "cannon":
			Dialog.text = "����������, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! ����� �����, �����, ������������ ����, �������� ������ ��������� ����� � ��� � ����." ;	// ccc feb06
			link.l1 = "����� ����, �� � �� ���� ������� ����� ��� ������ �����.";	// ccc feb06
			link.l1.go = "exit";

			link.l2 = "��� 5000 �������, �� ����� �� ��... ���... �������� �� ��� ���������� ������?";
			link.l2.go = "cannon2";
		break;

		case "cannon2":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = "��, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", � �������� ������ ���� �������� �������� �������� ��������. �� 5000 ������� �� ������ �� ��� ���� ����������. ������ ��� ��� ��������� �����." ;
			link.l1 = "��� ��� ���, ������� ���������! � ����� ���������� ��������� �� ����� ������� ��������. (..���� �� ��������� ��� �����..)";
			link.l1.go = "exit";
		break;

// ��������� �������� ���������               
		case "items":
		  if(taxdays>0 && rand(100)<120) // ���� �������� ��������� ����������� ������, ��������� ��������� �����, ����� �������� ������ ����������� ������ 
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = LinkRandPhrase("��, ������ � ���������, ��� ��������� ���, ��� � ����� ��������� � ������ ���������� ��� ���� ���������. � �����.. ���.. ������������ ��� �����, ����� ������� ������ ���� � ����� �� ����. �� ��� � ����� ������ ������������ ������, � ����� ������ ������ ��� ���� ��������� ����������� ������, ������� �������, ������ ��������� ���� ����� ���. ��, �����������, � �����, ��� ", "������, � ���� ���� ���������� � ����� �����: ��� ���������. ����� ��� �����, ����� ������ ������� ������� ��������� �����. ����� ������ ���� �������� ����, �����, �����, ����.. � ���� ���������� ����������� ������. ������� ", "����� ���, ��� �������� ����������, �� ������ �������� � ���� ��� ���������. ����� � ������ ������������ ������ � ������ ������� �������� ,����� ���������� ����� ��� �������� ����.. ���.. �����������, ����� ���� ��������� ������� ����� �� ����� ������, ������� � ���. ����� ��� �� ������, ��� ������� � �����. ���, ������, � ����������. �� �������������� ")  + "�� ����������� ���, ��������� ������ �� ��������� ���������� ����� ��������. ��� ��� � ��������� �� �������� ��� ���, ����� ��������� ��� �������� ��������� �� ���� �� ����." ;
  			link.l1 = "(��������� ��� �������� ���������? ����!) � ���, ������ ��� ����. � ����� ������, �� ������������ ������� �� ���� ��������� � ��������, ������� ���������! � ����� �������� ��������� �� ����� ������� ��������. (..���� �� ��������� ��� �����..)";
  			link.l1.go = "reward";
  			link.l2 = "���������? ��������� �����! �� ������ �������� ����, ����� � ������� ���� ���� ������, ��? �� ���� ���� ���� �� ������, ����� ���� ���. ������! ";
  			link.l2.go = "jewel";
			}
			else
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = "��, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", � ������ ��������� ���� ��������. ������, ��� ������ ������� ����������.. ���.. ������������, ������� ����� ��� � ���� ������� �����, ���� �� �������� ����. �� ������ ����� ������������ ��������� ������ ��� ����� �������� ���������� ������ ���������. �� ������ ������ ��� �� �������� ���, ��� ������, � ���� ���������, ��� �� ������ ��� ���, ����� �� ����� ��������." ;
  			link.l1 = "� �������, ��� ��� ���. ������, ��� ���� ������������� ��������?";
  			link.l1.go = "items2";
			}
		break;

		case "jewel":
		  GiveItem2Character(PChar, "jewelry"+ makeint(1 + rand(15)) );
		  if(rand(100)<20) // ���� ����������, ��������� ��������� ����� ��� �������� ���������� 
		  {
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;
  			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
  			PlaySound("OBJECTS\DUEL\man_hit6.wav");
  			Logit("���������? ������ ����� ����? ��� �� �� �� ����, �� �������� ���������� ���� ������ �������!");
			}
			else
		  {
  		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // ���������: ������ ��� �������. �������� �� ������ �����
  			Dialog.text = "��, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", ���� ������� ��� ���� �����. ������, ��� ������ ���������.. ���.. �������? ���� �� ������ ��� ���������� ���� ����� �����, ���� �� ������� � ��������� ������� ���� �������������?" ;
  			link.l1 = "������ �������! ��������������� ����������? ��� �� ������! ������ �� ����, � ���� ����������� �� ������ �����������. ������ ��!";
  			link.l1.go = "items";
			}
		break;

		case "reward":
			ChangeCharacterReputation(Pchar, 2);  // �������: ���������. �������� �� ������ �����
			Dialog.text = "��� ����� ����������� � ����� �������, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ". � ���� ��������, ����� �� ������ � ���������� ��������, ������ ���� � ���� ������!";
			link.l1 = "�, �� ������������, � �� ��� �� �������� � ����� ���������. ������, � ��� ���� ������ ������� �������. ������ �� ���� �� ����� � ����� ������, �� ���������� � ����������, ���������... � ������, ����������, �������� � ����� ���������.";
			link.l1.go = "items";
		break;

		case "items2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ref chr = characterFromID("B_keeper");	
			string locator = LAi_FindRandomLocator("reload");
			float x,y,z;
	  	   	ChangeCharacterAddressGroup(chr, pchar.location, "reload", locator);
  			GetCharacterPos(pchar, &x, &y, &z);
  			x = x+1;
  			TeleportCharacterToPos(chr, x, y, z);
  			Lai_SetActorType(chr);
  			LAi_ActorTurnToCharacter(chr, pchar);
  			LAi_ActorDialog(chr,pchar, "", 4.0, 1.0);
		break;


// ��������� �����
		case "attack1":
			Dialog.text = "����� ��������� �������� ������������, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! ��, ���� �� � ��� ���� �������� ���� ���������, ����������, ��� � �����...";
			link.l1 = RandSwear() + " ��������, ������! ���������� ��� �������, ��� �� �� ���������. ����������� ��������, �� ����� ���������� ������� ��� � ������� ���. � ���������� � ������� �����������...",
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = " ��������� ������� ������� � ��� ���� ��������������� ������������� ������������, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! �������� �����, ������� � �������... ��, ���� �� � ��� ���� �������� ���� ���������, ����������, ��� � �����...";
			link.l1 = RandSwear() + " ��������, ������! ���������� ��� �������, ��� �� �� ���������. ����������� ��������, �� ����� ���������� ������� ��� � ������� ���. � ���������� � ������� �����������...",
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: ����� ������������� ������ ��� �� �������� ����������� ����
			Ambush("native", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // �������: ���������. �������� �� ������ �����
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // �������: ����. �������� ��������� ����� �� ������ �����

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: ����� ������������� ������ ��� �� �������� ����������� ����
			Ambush("Soldier_Spa2",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // �������: ���������. �������� ������ �� ������ �����
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // �������: ����. �������� ��������� ����� �� ������ �����


			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
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
			Dialog.text = "��� �, ������, ����������� ���� ����� ��������. ������������ �������� ���� ���������� �� ������� ���������, ����� ������� ������� ��� ���������� ���� �������� � ������� ������� ������. ��������� ����� ���� �������������� ���, ����� ����������� ����� ������� � �������, ������� ������ ����� ����� ����� ��������� ��������� �������� ������� � �� ���������� ����� ��� ����������. ����������� ������ ������� ��� ����������� ����������. � ��������� ����� ��� ����� ����� ������������ � �������� ������ ��� ��� �������� ���������, ������ ��� ������ ��� ����� ��� � ���� �������������� � ������ �������: ��������� ����� �� ������������� ������. ��� �� ���." ;
			link.l1 = "���, � ���� ��������� ��� ����� ������� ������: ��� ����� ������ ����� ��� �����, �� ���������� � �����-������ �����.";
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", �� ������ ����� �� ������ ������ � ����������� ������������ ����������. ��� ����������, � ���������� - ��� ���.", "� ����� �� �������������� �����, � � �� ���� �� ��������. '����� ����, ������� �� ����������, ������� �� ������' ��� ������� �� �������� ���������� ������ �������.", "������ ������� ���������: �������� ���������� ��������. ��� ��� ������� �� ��������, ���� � ���� ��� �������������.");
			link.l1 = "������, � �������... ���������.";
			link.l1.go = "exit";
		break;


// ����� �� ����������� ����

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
