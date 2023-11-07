package org.example;

public class Photo {

    private String urlPhoto;

    private Long id;

    public Photo(Long id, String urlPhoto) {
        this.id = id;
        this.urlPhoto = urlPhoto;
    }
    public Photo( String urlPhoto) {
        this.urlPhoto = urlPhoto;
    }

    public void setUrlPhoto(String urlPhoto) {
        this.urlPhoto = urlPhoto;
    }

    public String getUrlPhoto() {
        return urlPhoto;
    }
}
