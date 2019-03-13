#include "stdafx.h"
#include "CMapManager.h"
#include "gamelib.h"

namespace game_framework
{
	CMapManager::CMapManager()
	{
		InitializeCBlockMap();
		nowMap = 0;
		loadMap = blockMap[0].loadMap;
	}


	CMapManager::~CMapManager()
	{
	}

#pragma region - GetMap -

	int CMapManager::GetNowMap()
	{
		return nowMap;
	}

	int CMapManager::GetUpMap()
	{
		return blockMap[nowMap].upMap;
	}

	int CMapManager::GetDownMap()
	{
		return blockMap[nowMap].downMap;
	}

	int CMapManager::GetLeftMap()
	{
		return blockMap[nowMap].leftMap;
	}

	int CMapManager::GetRightMap()
	{
		return blockMap[nowMap].rightMap;
	}
#pragma endregion

	void CMapManager::ChangeMap(int changeMap)
	{
		nowMap = changeMap;
	}

	void CMapManager::LoadBitmap(int loadMap)
	{
		//bmp.LoadBitmap(loadMap);
	}

	void CMapManager::onShow()
	{
		bmp.SetTopLeft(0, 0);
		bmp.ShowBitmap();
	}

	void CMapManager::InitializeCBlockMap()
	{
		for (int mapIndex = 0; mapIndex < MAX_MAP_NUMBER; mapIndex++) //��l��blockMap���W�U���k�a�ϸ�T�A�W�[�iŪ�ʨϥ�switch�ԭz
		{
			switch (mapIndex)
			{
				//���ǡG�ثe �W �U �� �k �A -1��ܤ��s�b
			case 0:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, 1, 2, 132);
				break;

			case 1:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, -1, 0, 111);
				break;

			case 2:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, 0, -1, 123);
				break;

			default:
				blockMap[mapIndex] = CBlockMap(-1, -1, -1, -1, -1, 0);
				break;
			}
		}
	}
}
