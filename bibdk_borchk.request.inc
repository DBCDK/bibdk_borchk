<?php
class bibdk_borchk extends TingClientRequest{

  protected $serviceRequester;
  protected $libraryCode;
  protected $userPincode;
  protected $userId;
  protected $action;
  protected $cacheKey;

  public function setServiceRequester($value=NULL) {
    $this->serviceRequester = $value;
  }

  public function getServiceRequester() {
    return $this->serviceRequester;
  }

  public function setLibraryCode($value=NULL){
    $this->libraryCode = $value;
  }

  public function getLibraryCode() {
    return $this->libraryCode;
  }

  public function setUserPincode($value = NULL) {
    $this->userPincode = $value;
  }

  public function getUserPincode() {
    return $this->userPincode;
  }

  public function setAction($value=NULL){
    $this->action = $value;
  }

  public function getAction(){
    return $this->action;
  }

  public function setUserId($value=NULL) {
    $this->userId = $value;
  }

  public function getUserId() {
    return $this->userId;
  }

  protected function getRequest() {
    $this->setParameter('action', 'borrowerCheckRequest');
    $this->setParameter('serviceRequester','bibliotek.dk');

    $params = array('libraryCode','userPincode','userId');
    foreach ($params as $parameter) {
      $getter = 'get' . ucfirst($parameter);
      if ($value = $this->$getter()) {
        $this->setParameter($parameter, $value);
      }
    }
    return $this;
  }
  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }
}