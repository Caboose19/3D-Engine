#include "C:\Users\Zach\source\repos\3D Engine\Application\pch.h"
#include "ResourceManager.h"

bool nc::ResourceManager::StartUp()
{
	return true;
}

void nc::ResourceManager::ShutDown()
{
}

void nc::ResourceManager::Update()
{
}

void nc::ResourceManager::RemoveAll()
{
	for (auto resource : m_resources)
	{
		resource.second->Destory();
	
		delete resource.second;
	}
	m_resources.clear();
	
}
