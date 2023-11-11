void InitRandomShipsNames()
{
	// Spain names
	int n = 0;
	n = AddStr2Array(&sRndShpSpName, n, "�������� X,�������,�������,�������,����� ���������,�����������,������,������,��������,��������,��������");		//some spanish ship names spell-checked by KAM
	n = AddStr2Array(&sRndShpSpName, n, "�����-���������,����������,�������,��������,������������,����,������,������,��������,������,���������,������,����������,�������");
	n = AddStr2Array(&sRndShpSpName, n, "��������,�������,�������,���������,�������������,������,�������� ��������,�������,���������,��������,�������,������,�����,�����");
	n = AddStr2Array(&sRndShpSpName, n, "���������,������,�����������,������,�����,������ �����,���������,�����,�����,��������,�������,�����,�������,��� �������");
	n = AddStr2Array(&sRndShpSpName, n, "������� ������,����������,�������,�������,������,�����������,�����������,����������,������,�������,�������,�������");
	n = AddStr2Array(&sRndShpSpName, n, "�������,������,������,�������,����,���������,������,�������,�������,����,���������,�����");
	n = AddStr2Array(&sRndShpSpName, n, "������,������������,��������,�������,����,�����,�����������,�������,����� I,����� ����� � �����,�����������,�����,����,������,������");
	n = AddStr2Array(&sRndShpSpName, n, "������������,�������,������ �����,������ �� �� ��������,��������,�����,���������,��������,�������,�������,����");
	n = AddStr2Array(&sRndShpSpName, n, "������,�������,�����������,���������� �����������,���������,�������,�����-��-������,������,�����,��������,������,������,�������,�����,���,������");
	n = AddStr2Array(&sRndShpSpName, n, "���������,�����,��������,����� �����������,����,���,��������� �����,����,�������� ����� �����,�������� ����,�������� ����,��������");
	n = AddStr2Array(&sRndShpSpName, n, "���������,�������,������,������ �������,������ ��������,���������,�����-�������,���������,������ ����,������ �����");
	n = AddStr2Array(&sRndShpSpName, n, "������ ������,������ ������,������ �������,������ ������,������ ������,������ ��������,������ ���������,������ ������,������ ����");
	n = AddStr2Array(&sRndShpSpName, n, "������ ����������,������ ��������,������ ��������,������ ����,������ ����������,������ ������,������ ������,������ ������");
	n = AddStr2Array(&sRndShpSpName, n, "������ ����,������ ��������,������ ����� ����������,������ ����� �����������,������,������ �������,������ ���������");
	n = AddStr2Array(&sRndShpSpName, n, "�����,������ �������,������ ����,������ ���,������ �������,������ �������,������ �����,������ �������");
	n = AddStr2Array(&sRndShpSpName, n, "������ ����� ����������,������ ���� �������,������ ���,������ �������,������ �����,������ ���������");
	n = AddStr2Array(&sRndShpSpName, n, "������ �������,������ ������,������ ������,������ �����,������ ����,������ �������,������ ��������");
	n = AddStr2Array(&sRndShpSpName, n, "������ ��������,������ �������,������ �����,������ �������,������ �����,������ ����������");
	n = AddStr2Array(&sRndShpSpName, n, "������ ����������,������ ��������,������ �������,������ ��������,������ �����,������ ���������");
	n = AddStr2Array(&sRndShpSpName, n, "������ �����,������ ����� ���������,������ ��������,������ ��������,������ ������,������ ����");
	n = AddStr2Array(&sRndShpSpName, n, "������ ����,������ �������,������ �������,������ ������,������ �������,������ ������,������,������ ������");
	n = AddStr2Array(&sRndShpSpName, n, "��������,�����,�������,�������,���������,������,������������,��������,������,������,�������� �����,������������,������,�������,��������");
	n = AddStr2Array(&sRndShpSpName, n, "�������,�������,����������,�����,������,�����,���������,�������,����,�������,�����,��������");
	if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN)
	{
		n = AddStr2Array(&sRndShpSpName, n, "�����,�����,��� ���� �����������,��������� ���� V,�������,������,����������,����� �������,�������,���-��-��-�����,������");
	}
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS)
	{
		n = AddStr2Array(&sRndShpSpName, n, "��������");
	}
	if(GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
	{
		n = AddStr2Array(&sRndShpSpName, n, "���� �� ����");
	}

	// England names
	n = 0;
	n = AddStr2Array(&sRndShpEnName, n, "������,����,�����,Ƹ����,��������,������,������,������������,������,�����,���,������,���������,���������,�������,��������,����");
	n = AddStr2Array(&sRndShpEnName, n, "��������,������,�������,������,��������,�������,�������,������,�������,���������,�������,���������,�������,���������,������,��������");
	n = AddStr2Array(&sRndShpEnName, n, "��������,������,�������,������,���������,��������,���������,�����,��������,�������,�������,�������,����,������,����,��������,�������");
	n = AddStr2Array(&sRndShpEnName, n, "������,��� �����,������,������������,������,������,����,������,��������,������,��������,��������,�����,�������,������,��������,�����,��������,�����");
	n = AddStr2Array(&sRndShpEnName, n, "������,�������,������,�������,��������,������,�������,��������,�����������,�������,������,������,������,׸���� �����,�����,�����,������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,����� �������,������,���������,���������,��������,��������,��������,������,�������,�������,�������,�����,���������,������,���������,���������,�������");
	n = AddStr2Array(&sRndShpEnName, n, "��������,�������,�������,��������,��������,������,���������,������,�������,���������,������,������,�������,����������,��������,�����,������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,������,����������,���������,��������,������,������,����������,�����������,���������,������,��������,��������,�����,������,������");
	n = AddStr2Array(&sRndShpEnName, n, "����������,���������,������,��������,������,�����,������,������,�����,�����,�����,�����,��������,����,������,��������,��������,�������������,�������,������");
	n = AddStr2Array(&sRndShpEnName, n, "���������,�������,�����,�����,��������,����,������������,������,��������,��������,�������,�����,������,��������,��������,�������,�������,�����");
	n = AddStr2Array(&sRndShpEnName, n, "������,������,���������,������ ��������,������,���,���,��������,�����,������,���������,����,��������,�������,���������,������������,��������,����������,��������������");
	n = AddStr2Array(&sRndShpEnName, n, "�����,�������,������,�������,��������,��������,��������,������,����������,�����������,���,�����,�����,�������,�����,�����,�������,�����,�����,�����,�������");
	n = AddStr2Array(&sRndShpEnName, n, "���������,�����,����,���������,��������,������,�������,���������,������,�������,�����,�����,���������,������,�����,�����,������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,�������,��������,������,��������,�����-����,��������,������,����������,���������,�����������,������,���������,����,������,������,��������,��������");
	n = AddStr2Array(&sRndShpEnName, n, "�����,�������,�����,��������,����,��������,����,�������,������,�����������,��������,������,������������,��������,���� ����, ������� ���,��������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,������,�����,�������,������,������������,����,����������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,����������,������,�����,�����,�����,��������,�������������,����������,������������,������������,������������,�����������,�����������");
	n = AddStr2Array(&sRndShpEnName, n, "��������,����,�������������,�����,�������,�����,�����,������,����,�������,���������,����,�����,�����,����,���������,�����,������,�������,����,������,������,�������,������,��������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,������,���,��������� �����,����������,�������,������,�����,����,����,�����������,������������,������������,��������������,�����,�������,����,������,����");
	n = AddStr2Array(&sRndShpEnName, n, "������,������,������,��������,�������,����������,�����,������,�������,������,�������,��������,����������,������,�����,����������,������,�����,����,�������");
	n = AddStr2Array(&sRndShpEnName, n, "��������,���������,������,�����,���������,������,������������,�����,���������,�����,�������,�������,�����,�����,�����,�������,������,�������,���������,��������,������,������,���������");
	n = AddStr2Array(&sRndShpEnName, n, "�����,�������,��������,������,�������������,����,������,������,������,�������,������,������,������,������,������,�������,������,����� ����������,���������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,����������,��������,�����,�������������,����,������,�����,������,������,��������,�������,��������,��������,�������� ����,�������,�����,��������������,������������");
	n = AddStr2Array(&sRndShpEnName, n, "������,�������,�������� �����,�����������,���������,�������������,���������,������,���������,��������,�������������,�����,������������,�����,�����,����,��������,�������");
	n = AddStr2Array(&sRndShpEnName, n, "����������� ���,����������� �������,�����,�������,�������,������,������,��������,�������,�������,����������,��������,�����,���������,������� �����,����������,�������,����,�����,�����������");
	n = AddStr2Array(&sRndShpEnName, n, "������,����,�������,�����������,��������,����������,�������,������,����,�����������,������,�����,�����,�����,������,�������,�����,�����,������,�������,������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,������,������,�������,�������������,����-���,�������,��������,������,��������,������,�����,�������,�����,����������,��������,�������,����,�����,�����,������,����������,������,���� ������");
	n = AddStr2Array(&sRndShpEnName, n, "�������,�������,��������������,��������,���������,���������,������,��������,��������������,��������,������,������,����������,��������,������,������,�����,������������,��������,����,������,�������,��������,���������");
	n = AddStr2Array(&sRndShpEnName, n, "�����,������,�����,��������,�������,������,������,������������,����������,�����������,������,������,�������������,����������,����,������ �����,���,����� ������,���������,���������,��������,�����,��������,�����,����");
	if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN)
	{
		n = AddStr2Array(&sRndShpEnName, n, "��������,�������� ���������,����,��� ������� �����");
	}
	if(GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		n = AddStr2Array(&sRndShpEnName, n, "��������,������ �����");
	}
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS)
	{
		n = AddStr2Array(&sRndShpEnName, n, "�����,������� ����");
	}
	if(GetCurrentPeriod() == PERIOD_NAPOLEONIC)
	{
		n = AddStr2Array(&sRndShpEnName, n, "����������,���,�����");
	}

	// France names
	n = 0;
	n = AddStr2Array(&sRndShpFrName, n, "�����,�������,�������,��������,������,�����������,���������������,����,���������,������,�������,���������,����������,���������,�������,��������,������,�������,���������,��������");		//some french ship names spell-checked by KAM
	n = AddStr2Array(&sRndShpFrName, n, "��������,�������,�����,������,������������,��������,������,��������,������������,�����,��������,�����,�������,������,������,�����,�������,�������,�����,��������,�������");
	n = AddStr2Array(&sRndShpFrName, n, "��������,������,������,�����,��������,�����,��������,�������,�����������,������ ���������,�����,�������,�������,��������,���������,�������,������,�������,���������");
	n = AddStr2Array(&sRndShpFrName, n, "������,����,���������,����,��������,��������,�������,���������,����������,��������,���������,������,�����,������,�������,������,�������,�������,����������,������");
	n = AddStr2Array(&sRndShpFrName, n, "�������������,���������,���������,��������,������,�������,�������,���������,�����������,��������,�����������,�����������,���������");
	n = AddStr2Array(&sRndShpFrName, n, "��������,����������,�������,������,������,�������,�������,������,������,������,�������,������,�����,�������,������,������,������,�������������,��������");
	n = AddStr2Array(&sRndShpFrName, n, "������,������,�������,�����,������,���������,������ ��� ������,����� ��������,����� ������,������,������ �����������,������ �����,�����,�����,������,�����,�������,�����,����������");
	n = AddStr2Array(&sRndShpFrName, n, "�������,��������,�����,�������,�������,������,���������,�����������,��������������,���,������,�������,�����,������,������������,�������,�����,���,����������,�����������,������,����������");
	n = AddStr2Array(&sRndShpFrName, n, "��������,�����������,������,������,�����,�������,�����,���������,��������,������,��������,��������,�����������,�����,��������,�������,��������,�����������,�������,�����,�������,����������");
	n = AddStr2Array(&sRndShpFrName, n, "�������,���������,����,��������� �����,��������,�������,����,������,����,����,��������,��������,�����,����������,��������,������,��������,��������,�������������,������������,�����������,��������");
	n = AddStr2Array(&sRndShpFrName, n, "��������,�������������,�����������,������������,���������,��������,���������,�����������,������,���������,�����������,�����������,��������,������,����������,��� ����,����,�����,������,������������,����������");
	n = AddStr2Array(&sRndShpFrName, n, "������,������,������,�������,������,�������,���������,���,�����,������,�������,������������,������������,�����,�����������,�����,�������,����������,������,�����,������,����������,��������");
	n = AddStr2Array(&sRndShpFrName, n, "���������,�������,��������,��������,�������,����,��������,������,�����,������,�������,�����,��������,������,�������,������ ����������,�����,�����,�����,������,�����,�������,������");
	n = AddStr2Array(&sRndShpFrName, n, "�������,�������,������,�����,�������,�����,���������,���������,������,��������� ������,�����,�����������,������,������,������,�������,�����������,�������,������������������,�������,��������,����������");
	n = AddStr2Array(&sRndShpFrName, n, "��������,����������,������,��������,��������,������������,�������,���������,�������,�����,������������,�����,���������,�����,�������������,�����������,�������������,��������,������,�����,�������,������");
	n = AddStr2Array(&sRndShpFrName, n, "��������,�������,�����,����������� ������,������,��������,������ �������,�������,�������,�������,�������,�������,���������������,����,���������,�������������,������������,�������,���������,��������,���������,������");
	n = AddStr2Array(&sRndShpFrName, n, "������ ���,������ ������,��������,�������,������,������,������������,��������������,�����������,��������,�����,������,������,�����,������,�����,������,�������,������,�������,��������");
	n = AddStr2Array(&sRndShpFrName, n, "��������,����,��������,���������,�������,�����,��������,�������,��������,�������������,���������,�������,������,����������,�������,������,�����,��������,��������������");
	n = AddStr2Array(&sRndShpFrName, n, "������,�����������,��������,�������,������,������������,�������,��������,��������������,������,������,���������,�����");
	if(GetCurrentPeriod() == PERIOD_NAPOLEONIC)
	{
		n = AddStr2Array(&sRndShpFrName, n, "�������� �����,�������� �������,�������� ������ ���,��������");
	}
	else
	{
		n = AddStr2Array(&sRndShpFrName, n, "����������� �������,����������");
	}

	// Pirate names
	n = 0;
	n = AddStr2Array(&sRndShpPiName, n, "�����������,������ �����������,���� �����������,������� ����������,׸���� �����,�����,�������������,�����,�������,�����,����,�������,����������,������,����� ��������,����� ������,���������,���������,������,����������,��������,��������,������������");		//some pirate ship names spell-checked by KAM
	n = AddStr2Array(&sRndShpPiName, n, "��������,������������,�����������,����� �������,������,��������,��������� �����,��������,�����,��������,��������,�������,�����,���������,��������,��������");
	n = AddStr2Array(&sRndShpPiName, n, "�������,�������,����������� �����,������,�����,�������,�����,������� ����,���������,���������,������,��������� ������,�����,�����������,���������,�������");
	n = AddStr2Array(&sRndShpPiName, n, "������,������,����������,�������,�����������,�����������,������������������,���������,��������,����������,����������� �����,������,����,�������,���������,��������,�������,�������,������,����,��������");
	n = AddStr2Array(&sRndShpPiName, n, "������,�����,�����,�����,��������,�������,�����,������,������,�������,������,��������,�������,������,����������,�����,������,�������,�����,������,�������");
	n = AddStr2Array(&sRndShpPiName, n, "��������� ����,�������,��������,��������,����������,�������� ������,�������� ������,�������� ������,�������,�������,���������,������ �������,���������� ������,������� ������,��������� ������,������,��������� ������");
	n = AddStr2Array(&sRndShpPiName, n, "������,�����,��,�����������,�������,��� �������,������,������,�����,������,������,������,������������,������,�������,�������,���������");
	n = AddStr2Array(&sRndShpPiName, n, "������,�����,������� ������,������� �����,��������� ������,��������� �����,�����������,���������� ����,׸���� ��������,׸���� ������,������� ��������,�������,�������,��������,׸���� ������,��������");
	n = AddStr2Array(&sRndShpPiName, n, "������� ������,����� ������,������� ������,׸���� ������,׸���� ������,������ �������,�������,������,������� ������,������� ������,������� ��������,������,������� ����,׸���� �����,������� �����,������ ����,����,������");
	n = AddStr2Array(&sRndShpPiName, n, "������ �����,��������� ������,�������,׸���� ������,������� ������,�������,�������� ���������,�������,�����,��������������,�����,�������,������,�����,׸���� �����,������� �����,������� �����");
	n = AddStr2Array(&sRndShpPiName, n, "������,���������� ����,������ ����,������ �������,���������,�����,������� ������,�������,���������,������,���������� �� ���,������� ��� ������,�������,�����,��������,������� ����,�����,��������");
	n = AddStr2Array(&sRndShpPiName, n, "�������,������,���� ������,���������� �����������,������������,������� ���������,�������,����� ���,����������,������-������-�������,����� ����,�����,�����,����");
//	n = AddStr2Array(&sRndShpPiName, n, "׸���� ������,������ �����");	// LDH if this line is being used, delete it - 04Jan09
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS)
	{
		n = AddStr2Array(&sRndShpEnName, n, "����� �������� ����,������ ������");
	}
		
	// Holland names
	n = 0;
	n = AddStr2Array(&sRndShpHoName, n, "�������,��������,������,����������,��������,�����,������� ������,�������,������� ������,������,�����������,������,������������ ������,�������� ����,���������,�������,����,������������ ���");
	n = AddStr2Array(&sRndShpHoName, n, "�����,������,������,��������,����������,׸���� ���,������,�������� �����,����������,��������,������� ���,������� ������,����������� ���,����,���������,����� ������,�������� �����");
	n = AddStr2Array(&sRndShpHoName, n, "�����,��������,������,������,�������,������,����������,���������,���� ���������,���� ������,���������,��������,������� ���������,��������,������ ���������,���� ��������");
	n = AddStr2Array(&sRndShpHoName, n, "������,������������ ������,��������,���� �����,����������� ���,�������� �������,������,����� ���������,���� ������������,������������ ������,���-����,����������� ���������,������������,����");
	n = AddStr2Array(&sRndShpHoName, n, "���� ���������,��������� �����,������� ������,����� ������,���� ����������,��������,�������,��������� �����,������������,�����������,�������,��������,����� ������");
	n = AddStr2Array(&sRndShpHoName, n, "��������,���� V,�������� ������,�������� ������,�����,������");

	// Portugal names
	n = 0;
	n = AddStr2Array(&sRndShpPoName, n, "�������� �����,��� ������ I,�����,�����-��-���������,����������� �����,���� ��� ������,����� I,������,��������� �����,����� ������,�������� ����������,������ ������� � ������ �����,����� �� ����,�������� �� ����������,��� ��� �� ������");		//some portuguese ship names spell-checked by KAM
	n = AddStr2Array(&sRndShpPoName, n, "�������� ��� �����,������ �����,������ ���-��������,������ �� �������,���-���������,������,�����,��������,�������,��������� ��������,������,����� ��������,������,��������,�����,������,������,�������,����-���,�������,�����");
	n = AddStr2Array(&sRndShpPoName, n, "��������� ��������,������,�����,������,������,������� � ���� �����,������ �������,������ �������,���������,����������� ���������,������ ��� �������,������� �������,������ �������,���,�����,������,�������,�����,�������,����");
	n = AddStr2Array(&sRndShpPoName, n, "����������,������� ����,��������,������,�����,�������,����������,������,���������,������,�������,��������,��������,��������,����-�����,��������,�����-����������,����,��������,������,��������,�������,�������� ������,����������� ����");
	n = AddStr2Array(&sRndShpPoName, n, "������,���������,�������� ���� ������,�����-�������,����,�����,��������,������,������,������,����� �� ����,��������� �� �������,������� ���������� ������,�������� ���� ����,����� �� ����,����-���,������");
	n = AddStr2Array(&sRndShpPoName, n, "����,������,������,��������,����� ���,����������� ����,���� �������,����� �������,������� ���� ��������,������� ������� �� �����,�������� ������,�������� ������� �����,�������� �������� ������,���� ��������");
	n = AddStr2Array(&sRndShpPoName, n, "������� �������,������� ������� �'���,������� �� ��������,������ �������,������� ����,������ �� �������,���� ����,�������� ��������,�������� � �����,����������� ����� ��������");
	n = AddStr2Array(&sRndShpPoName, n, "�������,��������,�����,�����,���������,�����,���������,��������,�����������,���������,����,������,���������,������");
	n = AddStr2Array(&sRndShpPoName, n, "������ ����,������ ����������,������ ������,���-����-��-����,����� �����,������ �������,���� ���������,������ ����,������ ���������,������ �����,������ �����,������� ������,����� �����,������ ����");
	n = AddStr2Array(&sRndShpPoName, n, "������� ������,������� ���������,������� ����,���-����-��������,���������,������ ������,���-��-����,�����-�����,���-����-��-�������,����� �����,������ �����,��� ����� I,������ �������,��������� ������");
	n = AddStr2Array(&sRndShpPoName, n, "����� ����,����������� ��������,��������� ����,������ �������,������ ����,������ �����,������ ��������,������ �����,������ �������,������ �����,������ ��������,������� �����,������� ����,�������� ������ ���������");
	n = AddStr2Array(&sRndShpPoName, n, "��������,���� �����,������� ����,������ ��������,׸���� ������,������ ����������,���� ���,����� ����,������ ������,���� ������,���� �����������,������ �������,������ ������");
	n = AddStr2Array(&sRndShpPoName, n, "׸���� ������,������ ������,������ �������,������� �����,������ �����,�����-�����,����������� ����,����������,��������,���������,������� �����,���-��-�������,�������,������������ ���");
	n = AddStr2Array(&sRndShpPoName, n, "����� ������,�������� ����,������ �����,�������,������� �����,���������,����� �����,������� ��������,�������,���-����,��������� �����,������ �����,������� ���,����� ���");

	// American names
	n = 0;
	n = AddStr2Array(&sRndShpAmName, n, "�����,������,�������,����,���������,�������,����� �����,���������,�����,��������,�������� ������,����� ����,�����,����� ������,������,������,������ ����,����������,����������,�����,��������,��������,������ �. ������,���������,��������,�������,�������,�����,��������,��������,��������,������������");
	n = AddStr2Array(&sRndShpAmName, n, "��������,�����������,���������,�����������,����������,�����,����,���,��������,�������,�����,�������,���,��������,��������,����������,�����������,�������,���,������,�����������,������� ����������,�������,�������,������,�������,��������,����,������� ����,������,�����������");
	n = AddStr2Array(&sRndShpAmName, n, "������,�������,��������,���������,�������,������,�����,�������,�������,������,������ ���,�������������,���������,����������,�����,������,���� ���������,�������,������,����������,�������,�����������,�������,������,���� ����,��������,�����������,��������,��������");
	n = AddStr2Array(&sRndShpAmName, n, "������,�����,����������,���������,��������,������,���-�������,���-������,���-����,�������,�������,�������� ��������,�����,�������,������,������ �����,�������,������,������������,�����������,��������,���������,������,����������,��������,�������,�����,���������,��������,���������");
	n = AddStr2Array(&sRndShpAmName, n, "��������,����,��������,��������,�������,���������,������������,���-������,������,��������,������ ��������,�����,�������,��������,�������,�����,����� ��������,����������,������ ���������,������ ���,������������,�������,�������,�����,������,����������� �����,�������,������,���������,������,���,��������");
	if(GetCurrentPeriod() == PERIOD_NAPOLEONIC)
	{
		n = AddStr2Array(&sRndShpEnName, n, "��������,����������,���� �����,������ ���������,���������");
	}	
	// Swedish names
	n = 0;
	n = AddStr2Array(&sRndShpSwName, n, "���������,���������,�����,����� ��������,������,�����,����,��������,������,������,������,�������,������,�������,������,���������,�������,����,������,�������");
	n = AddStr2Array(&sRndShpSwName, n, "�����,�����,�������,������,��������,�������,�������,��� �����,���,��� ����,��� ���,����,�������,������,�����,���������,���������� ���,����� �������,������,������");
	n = AddStr2Array(&sRndShpSwName, n, "�������,�����������,������� ������,������,�����,�������,������,��������,�������,��������,������,�����������,�����,����,��������,��������,�������,�������,������� ������,������� �����");
	n = AddStr2Array(&sRndShpSwName, n, "������� ���,������� ����,������������,�����,������,���������,������� ������,�������� ������,������� ����,�������,������,������ ��������,�������� ������,�������,���������,����-���,��������,������ ���,������ �������,�������");
	n = AddStr2Array(&sRndShpSwName, n, "���� ���,���� ��������,������,���� ������,������,������ ���,������,��������������,����,������,�������,���������,�����,��������,������� �����,�������,��������,��������,�����,������");
	n = AddStr2Array(&sRndShpSwName, n, "����,������,����� ���,������,����,�������,������,����,������,��������������,������,�������,������,������,����������,����,����,����,��������,�������");
	n = AddStr2Array(&sRndShpSwName, n, "������,���,������,�������,�����,���������,�����,�����,���������,��������,������������,�����,����,�����,����������,�����������,����,������,�������� ������,����");
	n = AddStr2Array(&sRndShpSwName, n, "����,�����,�������,�������,������,�����,������� ������,������� ���,������� ������,�������,������,�������� �����,��������,����,������ ������,������ ����,������ �����,������,�����,��������");
	n = AddStr2Array(&sRndShpSwName, n, "������,����������,�������,������,���������,����,�����������,������,����������,�����,�����,������,׸���� ���,׸���� ������,׸���� �������,����,���������,����,������,��� ������");
	n = AddStr2Array(&sRndShpSwName, n, "��� ����,��������,����,����,������� �������,�������������,�����,�����,�����,����,������,��������");
}
